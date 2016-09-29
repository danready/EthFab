#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Socket to communicate with CollSoft server
    QTcpSocket* _pSocket;

private slots:
    void readTcpData();
    void Errore(QAbstractSocket::SocketError sock_error);
    void on_actionConnect_triggered();
    void AppendMessageToQtextEdit(QTextEdit* MexArea, QString Message);
    void on_SendBaseCase_clicked();
};

#endif // MAINWINDOW_H
