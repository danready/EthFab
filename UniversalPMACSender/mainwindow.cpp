#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

/*
 * General definitions.
 */
#define GEOBRICK_IP_1 "192.168.10.3"
#define GEOBRICK_PORT_1 1025

#define GEOBRICK_IP_2 "192.168.10.4"
#define GEOBRICK_PORT_2 1025

#define GEOBRICK_IP_LOCAL "127.0.0.1"
#define GEOBRICK_PORT_LOCAL 1112


/*
 * Definition for Simple Case
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

//Request type
#define VR_DOWNLOAD      0x40 //Simple Case
#define VR_UPLOAD        0xC0

//Request
#define VR_PMAC_GETRESPONSE 0xBF //Simple Case
#define VR_PMAC_SENDLINE    0xB0
#define VR_PMAC_GETLINE     0xB1
#define VR_PMAC_FLUSH       0xB3
#define VR_PMAC_GETMEM      0xB4
#define VR_PMAC_SETMEM      0xB5
#define VR_PMAC_SETBIT      0xBA
#define VR_PMAC_SETBITS     0xBB
#define VR_PMAC_PORT        0xBE
#define VR_PMAC_READREADY   0xC2
#define VR_CTRL_RESPONSE    0xC4
#define VR_PMAC_GETBUFFER   0xC5
#define VR_PMAC_WRITEBUFFER 0xC6
#define VR_PMAC_WRITEERROR  0xC7
#define VR_FWDOWNLOAD       0xCB
#define VR_IPADDRESS        0xE0

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

    ui->comboBox_RequestType->addItem("VR_DOWNLOAD");
    ui->comboBox_RequestType->addItem("VR_UPLOAD");

    ui->comboBox_Request->addItem("VR_PMAC_GETRESPONSE");
    ui->comboBox_Request->addItem("VR_PMAC_SENDLINE");
    ui->comboBox_Request->addItem("VR_PMAC_GETLINE");
    ui->comboBox_Request->addItem("VR_PMAC_FLUSH");
    ui->comboBox_Request->addItem("VR_PMAC_GETMEM");
    ui->comboBox_Request->addItem("VR_PMAC_SETMEM");
    ui->comboBox_Request->addItem("VR_PMAC_SETBIT");
    ui->comboBox_Request->addItem("VR_PMAC_SETBITS");
    ui->comboBox_Request->addItem("VR_PMAC_PORT");
    ui->comboBox_Request->addItem("VR_PMAC_READREADY");
    ui->comboBox_Request->addItem("VR_CTRL_RESPONSE");
    ui->comboBox_Request->addItem("VR_PMAC_GETBUFFER");
    ui->comboBox_Request->addItem("VR_PMAC_WRITEBUFFER");
    ui->comboBox_Request->addItem("VR_PMAC_WRITEERROR");
    ui->comboBox_Request->addItem("VR_FWDOWNLOAD");
    ui->comboBox_Request->addItem("VR_IPADDRESS");
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
    int i = 0;

    QByteArray data = _pSocket->readAll();

    //QString data_string(data);
    //you have to deep copy the QByteArray character by character because the received
    //string could content a termination character '\0' inside it.

    QString data_string;

    for (i = 0; i < data.size(); i++)
    {
        data_string += data.data()[i];
    }

    AppendMessageToQtextEdit(ui->textEdit_BaseCase, data_string);

}

MainWindow::~MainWindow()
{
    delete ui;
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

    //strncpy((char*)&EthCmd.bData[0],(const char*)cCommand,strlen(cCommand));

    //fprintf(stderr, "Computated: %u\n", EthCmd.wLength);

    QByteArray data((char *)&EthCmd, ETHERNETCMDSIZE + strlen(cCommand)); // <-- fill with data
    _pSocket->write( data );

}

void MainWindow::on_pushButton_SendStructure_clicked()
{
    ETHERNETCMD EthCmd;
    char cCommand[256];

    AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Command sent...");

    if (ui->comboBox_RequestType->currentText() == "VR_DOWNLOAD")
        EthCmd.RequestType = VR_DOWNLOAD;
    if (ui->comboBox_RequestType->currentText() == "VR_UPLOAD")
        EthCmd.RequestType = VR_UPLOAD;

    if (ui->comboBox_Request->currentText() == "VR_PMAC_GETRESPONSE")
        EthCmd.Request     = VR_PMAC_GETRESPONSE;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_SENDLINE")
        EthCmd.Request     = VR_PMAC_SENDLINE;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_GETLINE")
        EthCmd.Request     = VR_PMAC_GETLINE;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_FLUSH")
        EthCmd.Request     = VR_PMAC_FLUSH;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_GETMEM")
        EthCmd.Request     = VR_PMAC_GETMEM;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_SETMEM")
        EthCmd.Request     = VR_PMAC_SETMEM;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_SETBIT")
        EthCmd.Request     = VR_PMAC_SETBIT;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_SETBITS")
        EthCmd.Request     = VR_PMAC_SETBITS;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_PORT")
        EthCmd.Request     = VR_PMAC_PORT;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_READREADY")
        EthCmd.Request     = VR_PMAC_READREADY;
    if (ui->comboBox_Request->currentText() == "VR_CTRL_RESPONSE")
        EthCmd.Request     = VR_CTRL_RESPONSE;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_GETBUFFER")
        EthCmd.Request     = VR_PMAC_GETBUFFER;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_WRITEBUFFER")
        EthCmd.Request     = VR_PMAC_WRITEBUFFER;
    if (ui->comboBox_Request->currentText() == "VR_PMAC_WRITEERROR")
        EthCmd.Request     = VR_PMAC_WRITEERROR;
    if (ui->comboBox_Request->currentText() == "VR_FWDOWNLOAD")
        EthCmd.Request     = VR_FWDOWNLOAD;
    if (ui->comboBox_Request->currentText() == "VR_IPADDRESS")
        EthCmd.Request     = VR_IPADDRESS;

    EthCmd.wValue      = htons((u_int16_t) ui->lineEdit_wValue->text().toUInt());

    EthCmd.wIndex      = htons((u_int16_t) ui->lineEdit_wIndex->text().toUInt());

    EthCmd.wLength     = htons((u_int16_t) ui->lineEdit_wLenght->text().toUInt());

    strcpy(cCommand,ui->lineEdit_bData->text().toUtf8());

    strncpy((char*)EthCmd.bData,(const char*)cCommand,strlen(cCommand));

    //strncpy((char*)&EthCmd.bData[0],(const char*)cCommand,strlen(cCommand));

    //fprintf(stderr, "Inserted: %u\n", EthCmd.wLength);

    //fprintf(stderr, "Computated: %u\n",  htons((u_int16_t)strlen((const char*)cCommand)));

    //fprintf(stderr, "Command: %s\n", cCommand);

    QByteArray data((char *)&EthCmd, ETHERNETCMDSIZE + strlen(cCommand)); // <-- fill with data

    _pSocket->write( data );

}

void MainWindow::on_actionConnect_triggered()
{
    //main_window_log_file->LogFileExpertGUI_WriteOnLogFile("Connect to CollSoft server command clicked.");

    if(_pSocket->state() != QAbstractSocket::UnconnectedState)
    {
        _pSocket->disconnectFromHost();
    }

    _pSocket->connectToHost(GEOBRICK_IP_1, (quint16)GEOBRICK_PORT_1);

    if( _pSocket->waitForConnected(2000) ) {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to GeoBrick 1 Okay");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to GeoBrick 1 Okay");

    } else {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to GeoBrick 1 Failed");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to GeoBrick 1 Failed");

    }

}


void MainWindow::on_actionDeltaTau_PMAC_Geobrick_2_triggered()
{
    //main_window_log_file->LogFileExpertGUI_WriteOnLogFile("Connect to CollSoft server command clicked.");

    if(_pSocket->state() != QAbstractSocket::UnconnectedState)
    {
        _pSocket->disconnectFromHost();
    }

    _pSocket->connectToHost(GEOBRICK_IP_2, (quint16)GEOBRICK_PORT_2);

    if( _pSocket->waitForConnected(2000) ) {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to GeoBrick 2 Okay");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to GeoBrick 2 Okay");

    } else {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to GeoBrick 2 Failed");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to GeoBrick 2 Failed");

    }
}

void MainWindow::on_actionTest_LocalHost_triggered()
{
    //main_window_log_file->LogFileExpertGUI_WriteOnLogFile("Connect to CollSoft server command clicked.");

    if(_pSocket->state() != QAbstractSocket::UnconnectedState)
    {
        _pSocket->disconnectFromHost();
    }

    _pSocket->connectToHost(GEOBRICK_IP_LOCAL, (quint16)GEOBRICK_PORT_LOCAL);

    if( _pSocket->waitForConnected(2000) ) {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to Local Host Okay");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to Local Host Okay");

    } else {

       AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Connection to Local Host Failed");
       AppendMessageToQtextEdit(ui->textEdit_GeneralPurpose, "Connection to Local Host Failed");

    }
}
