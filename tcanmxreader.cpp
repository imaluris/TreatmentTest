#include "tcanmxreader.h"
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


void TCanMxReader::run() {
    // Il codice che vuoi eseguire nel thread separato
    stopFlag = false;
    while (!stopFlag) {
        // Leggi i dati CAN continuativamente
        // Legge i dati dalla CAN
        stat = canReadWait(hnd, &id, &data, &dlc, &flags, &timestamp, 100);

        if (stat < 0 && stat != canERR_NOMSG) {
            qCritical() << "Failed to read CAN data, status:" << stat;
        } else if (stat != canERR_NOMSG) {
            // Converti il timestamp in formato "T1933ms"
            QString timestampFormatted = QString("T%1ms").arg(timestamp);


            // Crea il messaggio con il formato richiesto
            QString message = QString("%1      ID %2 DLC-%3 |").arg(timestampFormatted).arg(id, 8, 16, QChar('0')).arg(dlc, 2, 10, QChar('0'));

            // Aggiungi i byte in formato esadecimale al messaggio
            for (int i = 0; i < dlc; i++) {
                message += QString(" %1").arg(data[i], 2, 16, QChar('0')).toUpper();
            }

            // Emmetti il segnale con il messaggio
            emit newCanDataReceived(message);
        }
        // Puoi aggiungere una piccola pausa per evitare che il thread prenda troppo CPU
    }
}

void TCanMxReader::stop() {
    stopFlag = true;
}

void processItem(const QString &item){

}
