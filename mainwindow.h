#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCheckBox>



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

    QPlainTextEdit* getPlainText();
    QPushButton* getStartButton();
    QPushButton* getStopButton();
    QCheckBox* getDisplayType();

private slots:
    void onNewCanDataReceived(const QString &message);  // Slot per ricevere i messaggi CAN

public slots:
    void on_pushStartButton_clicked();
    void on_pushStopButton_clicked();
    void onCheckboxToggled(bool checked);

signals:
    void newCanMessage(QString message);  // Segnale per un nuovo messaggio CAN

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
