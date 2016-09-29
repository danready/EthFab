#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

/*
 * General definitions.
 */
#define GEOBRICK_IP "192.168.10.4"
#define GEOBRICK_PORT 1025

/*
 * Definition for Simple Case
 *
 */

typedef struct tagEthernetCmd
{
  u_int8_t   RequestType;
  u_int8_t   Request;
  u_int16_t  wValue;
  u_int16_t  wIndex;
  u_int16_t  wLength;
  u_int8_t   bData[1492];
} ETHERNETCMD,*PETHERNETCMD;

#define ETHERNETCMDSIZE 8

#define VR_PMAC_GETRESPONSE 0xBF
#define VR_UPLOAD        0xC0
#define VR_DOWNLOAD      0x40

/*
 * Definition of general purpose case.
 *
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Socket to communicate with CollSoft program
    _pSocket = new QTcpSocket( this );

    //Disabling Nagle algorithm in order to have real time response from Server
    _pSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    //Binding CollSoft socket with readTcpData() and with Error SLOT
    connect( _pSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );

    connect(ui->lineEdit_BaseCase, SIGNAL(returnPressed()),ui->SendBaseCase,SIGNAL(clicked()));
}

//This slot is used to catch the errors from the TCP/IP communication between the ExpertGUI and the CollSoft server.
void MainWindow::Errore(QAbstractSocket::SocketError sock_error)
{
    AppendMessageToQtextEdit(ui->textEdit_BaseCase, _pSocket->errorString());
    AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, _pSocket->errorString());
}

//This methods analyze the input sent to this GUI from the server
void MainWindow::readTcpData()
{
    QByteArray data = _pSocket->readAll();

    QString data_string(data);

    AppendMessageToQtextEdit(ui->textEdit_BaseCase, data_string);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    //main_window_log_file->LogFileExpertGUI_WriteOnLogFile("Connect to CollSoft server command clicked.");

    _pSocket->connectToHost(GEOBRICK_IP, (quint16)GEOBRICK_PORT);

    if( _pSocket->waitForConnected(1000) ) {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to GeoBrick Okay");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to GeoBrick Okay");

    } else {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to GeoBrick Failed");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to GeoBrick Failed");

    }

}

void MainWindow::AppendMessageToQtextEdit(QTextEdit* MexArea, QString Message)
{
    //Message += "\n---------------------";

    //QString PromptMessage("> ");

    MexArea->append("> " + Message);
    QTextCursor c2 =  MexArea->textCursor();
    c2.movePosition(QTextCursor::End);
    MexArea->setTextCursor(c2);
    MexArea->ensureCursorVisible();
}

void MainWindow::on_SendBaseCase_clicked()
{

    ETHERNETCMD EthCmd;
    char cCommand[256];

    AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Command sent...");

    EthCmd.RequestType = VR_DOWNLOAD;
    EthCmd.Request     = VR_PMAC_GETRESPONSE;
    EthCmd.wValue      = 0;
    EthCmd.wIndex      = 0;
    //strcpy(cCommand,"RHX$0");
    strcpy(cCommand,ui->lineEdit_BaseCase->text().toUtf8());
    EthCmd.wLength     = htons((u_int16_t)strlen((const char*)cCommand));
    strncpy((char*)EthCmd.bData,(const char*)cCommand,strlen(cCommand));

    QByteArray data((char *)&EthCmd); // <-- fill with data
    _pSocket->write( data );

}
