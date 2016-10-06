//This program will be very useful to test our new Geobrick.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTcpSocket>
#include <vector>



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

    bool decoding_error;

private slots:
    void readTcpData();
    void Errore(QAbstractSocket::SocketError sock_error);
    void on_actionConnect_triggered();
    void AppendMessageToQtextEdit(QTextEdit* MexArea, QString Message);
    void on_SendBaseCase_clicked();
    void on_pushButton_SendStructure_clicked();
    void on_actionDeltaTau_PMAC_Geobrick_2_triggered();
    void on_actionTest_LocalHost_triggered();
    void HumanReadableError (int error_code);
    void DecodeErrors ( std::vector<int>& decode_array, unsigned int converting_number );
    void DecodeSum ( std::vector<int>& decode_array, unsigned int converting_sum, int table_pointer );
    void PartialDecoding (std::vector<int>& tmp_vector_reference, int converting_sum);
};

#endif // MAINWINDOW_H
