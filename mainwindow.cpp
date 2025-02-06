#include "mainwindow.h"
#include "globals.h"
#include "./ui_mainwindow.h"
#include "canlib.h"
#include "tcanmxreader.h"

TCanMxReader worker;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&worker, &TCanMxReader::newCanDataReceived, this, &MainWindow::onNewCanDataReceived);
    connect(ui->displayType, &QCheckBox::toggled, this, &MainWindow::onCheckboxToggled);
    connect(ui->ButtonStart, &QPushButton::clicked, this, &MainWindow::on_pushStartButton_clicked);
    connect(ui->ButtonStop, &QPushButton::clicked, this, &MainWindow::on_pushStopButton_clicked);

    ui->canList->setReadOnly(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

// Funzione per accedere al QPlainTextEdit
QPlainTextEdit* MainWindow::getPlainText()
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

void MainWindow::onNewCanDataReceived(const QString &message)
{
    // Aggiungi il messaggio al QPlainTextEdit
    ui->canList->appendPlainText(message);
}

void MainWindow::onCheckboxToggled(bool checked) {
    // Modifica la variabile in base allo stato del checkbox
    CanDisplayType displayType = checked ? Fixed : Standard;

    // Stampa lo stato della variabile per il debug
    qDebug() << "Variabile isChecked:" << displayType;
}
