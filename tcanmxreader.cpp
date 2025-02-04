#include "tcanmxreader.h"
#include "mainwindow.h"
#include "globals.h"
#include <QThread>
#include <QDebug>
#include "canlib.h"
#include <QListWidget>

int chanCount;
long id;
unsigned char data[8];
unsigned int dlc, flags;
unsigned long timestamp;
bool stopFlag = true;

void readCanData() {
    // Legge i dati dalla CAN
    stat = canReadWait(hnd, &id, &data, &dlc, &flags, &timestamp, 100);

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

void TCanMxReader::run() {
    // Il codice che vuoi eseguire nel thread separato
    stopFlag = false;
    while (!stopFlag) {
        // Leggi i dati CAN continuativamente
        readCanData();
        // Puoi aggiungere una piccola pausa per evitare che il thread prenda troppo CPU
    }
}

void TCanMxReader::stop() {
    stopFlag = true;
}
