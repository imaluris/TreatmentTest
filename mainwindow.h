#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>


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

signals:
    void newCanMessage(QString message);  // Segnale per un nuovo messaggio CAN

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
