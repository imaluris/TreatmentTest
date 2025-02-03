#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
