#include "mainwindow.h"
#include "globals.h"
#include "./ui_mainwindow.h"
#include "canlib.h"

TCanMxReader worker;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->ButtonStart, &QPushButton::clicked, this, &MainWindow::on_pushStartButton_clicked);
    connect(ui->ButtonStop, &QPushButton::clicked, this, &MainWindow::on_pushStopButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Funzione per accedere al QListWidget
QListWidget* MainWindow::getWidgetList()
{
    return ui->canList;  // Assicurati che il widget nel .ui si chiami 'widgetList'
}

void MainWindow::on_pushStartButton_clicked()
{
    // Inizializza la libreria CAN
    canInitializeLibrary();

    // Apri il canale CAN 0 in modalità esclusiva
    hnd = canOpenChannel(0, canOPEN_EXCLUSIVE);
    if (hnd < 0) {
        qCritical() << "Failed to open CAN channel, status:" << hnd;
    }

    stat = canSetBusParams(hnd, canBITRATE_500K, 0, 0, 0, 0, 0);
    if (stat != canOK) {
        qCritical() << "canSetBusParams failed, status:" << stat;
    }

    stat = canBusOn(hnd);
    if (stat < 0) {
        qCritical() << "canBusOn failed, status:" << stat;
    }

    qDebug() << "CAN channel opened successfully.";

    // Connessione del segnale con una funzione lambda nel thread principale
    QObject::connect(&worker, &TCanMxReader::messageFromWorker, [](const QString &message) {
        qDebug() << "Main thread received: " << message;
    });

    // Avvia il thread
    worker.start();
}

void MainWindow::on_pushStopButton_clicked()
{
    stat = canClose(hnd);
    if (stat < 0) {
        qCritical() << "Failed to close CAN channel.";
    }
    hnd = canINVALID_HANDLE;

    worker.stop();
}
