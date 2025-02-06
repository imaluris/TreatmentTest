#include "mainwindow.h"
#include "canlib.h"
#include <QApplication>
#include <QPushButton>


CanHandle hnd;
canStatus stat;
MainWindow *w;
QPlainTextEdit *listCan;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");

    w = new MainWindow();  // Crea il puntatore a MainWindow
    w->show();

    // Esegui l'applicazione Qt senza bloccare il thread principale
    int result = a.exec();

    // Chiudi il canale CAN al termine dell'app


    return result;
}
