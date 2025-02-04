#ifndef TCANMXREADER_H
#define TCANMXREADER_H

#include <QObject>
#include <QThread>


class TCanMxReader : public QThread {

    Q_OBJECT

signals:
    void messageFromWorker(const QString &message);  // Segnale per comunicare con il main thread

public:
    void stop();

protected:
    void run() override;  // Metodo che viene eseguito nel thread separato

};

#endif // TCANMXREADER_H
