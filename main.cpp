#include "mainwindow.h"
#include "canlib.h"
#include <QTimer>
#include <QListWidget>

#include <QApplication>

CanHandle hnd;
canStatus stat;
MainWindow *w;
QListWidget *listCan;
int chanCount;
long id;
unsigned char data[8];
unsigned int dlc, flags;
unsigned long timestamp;

void readCanData() {
    // Legge i dati dalla CAN
    stat = canRead(hnd, &id, data, &dlc, &flags, &timestamp);

    if (stat < 0 && stat != canERR_NOMSG) {
        qCritical() << "Failed to read CAN data, status:" << stat;
    } else if (stat != canERR_NOMSG) {
        QString message = QString("ID: %1 Data:").arg(id);

        // Aggiungi i byte in formato esadecimale al messaggio
        for (int i = 0; i < dlc; i++) {
            message += QString(" %1").arg(data[i], 2, 16, QChar('0')).toUpper();
        }

        message += QString(" DLC: %1 Flags: %2 Timestamp: %3").arg(dlc).arg(flags).arg(timestamp);

        listCan = w->getWidgetList();
        listCan->addItem(message);
        listCan->setCurrentItem(listCan->item(listCan->count() - 1));


    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow();  // Poi crea il puntatore a MainWindow
    w->show();

    // Inizializza la libreria CAN
    canInitializeLibrary();

    // Apri il canale CAN 0 in modalità esclusiva
    hnd = canOpenChannel(0, canOPEN_EXCLUSIVE);
    if (hnd < 0) {
        qCritical() << "Failed to open CAN channel, status:" << hnd;
        return -1;
    }

    stat = canSetBusParams(hnd, canBITRATE_500K, 0, 0, 0, 0, 0);
    if (stat != canOK) {
        printf("canSetBusParams failed, status=%d\n", stat);
        exit(1);
    }

    stat = canBusOn(hnd);
    if (stat < 0) {
        printf("canBusOn failed, status=%d\n", stat);
        exit(1);
    }

    qDebug() << "CAN channel opened successfully.";

    // Imposta un timer per leggere i dati CAN ogni 100 ms
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, readCanData);
    timer.start(100);  // 100ms = 10 letture al secondo

    // Esegui l'applicazione Qt
    int result = a.exec();

    // Chiudi il canale CAN al termine dell'app
    stat = canClose(hnd);
    if (stat < 0) {
        qCritical() << "Failed to close CAN channel.";
    }
    hnd = canINVALID_HANDLE;

    return result;
    return a.exec();


}
