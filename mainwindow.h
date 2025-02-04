#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QListWidget* getWidgetList();
    QPushButton* getStartButton();
    QPushButton* getStopButton();

public slots:
    void on_pushStartButton_clicked();
    void on_pushStopButton_clicked();

signals:
    void newCanMessage(QString message);  // Segnale per un nuovo messaggio CAN

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
