#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <vector>

using namespace std;

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

void MainWindow::PartialDecoding (vector<int>& tmp_vector_reference, int converting_sum)
{

    /*
    1 2 4 8

    3 5 9 6 10 12

    7 11 14

    15

    1:1
    2:2
    4:3
    8:4

    3:1&2
    5:1&3
    9:1&4
    6:2&3
    10:2&4
    12:3&4

    7:1&2&3
    11:1&2&4
    13:1&3&4
    14:2&3&4

    15:1&2&3&4
    */

    if (converting_sum == 1)
    {
        tmp_vector_reference.push_back(1);
    }
    else if (converting_sum == 2)
    {
        tmp_vector_reference.push_back(2);
    }
    else if (converting_sum == 4)
    {
        tmp_vector_reference.push_back(3);
    }
    else if (converting_sum == 8)
    {
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 3)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(2);
    }
    else if (converting_sum == 5)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(3);
    }
    else if (converting_sum == 9)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 6)
    {
        tmp_vector_reference.push_back(2);
        tmp_vector_reference.push_back(3);
    }
    else if (converting_sum == 10)
    {
        tmp_vector_reference.push_back(2);
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 12)
    {
        tmp_vector_reference.push_back(3);
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 7)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(2);
        tmp_vector_reference.push_back(3);
    }
    else if (converting_sum == 11)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(2);
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 13)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(3);
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 14)
    {
        tmp_vector_reference.push_back(2);
        tmp_vector_reference.push_back(3);
        tmp_vector_reference.push_back(4);
    }
    else if (converting_sum == 15)
    {
        tmp_vector_reference.push_back(1);
        tmp_vector_reference.push_back(2);
        tmp_vector_reference.push_back(3);
        tmp_vector_reference.push_back(4);
    }
}

void MainWindow::DecodeSum ( vector<int>& decode_array, unsigned int converting_sum, int table_pointer )
{
    vector<int> tmp_vector;
    vector<int>& tmp_vector_reference = tmp_vector;

    int i = 0;

    if (table_pointer == 0)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);

            //cout << "table_pointer 0 " << tmp_vector_reference[i] << endl;

        }

    }
    else if (table_pointer == 1)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);

            //cout << "table_pointer 1 " << tmp_vector_reference[i] << endl;
        }
    }
    else if (table_pointer == 2)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
        }
    }
    else if (table_pointer == 3)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
        }
    }
    else if (table_pointer == 4)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
        }
    }
    else if (table_pointer == 5)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
        }
    }
    else if (table_pointer == 6)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
        }
    }
    else if (table_pointer == 7)
    {
        PartialDecoding(tmp_vector_reference, converting_sum);

        for (i = 0; i < tmp_vector_reference.size(); i++)
        {
            decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
        }
    }
}

void MainWindow::DecodeErrors ( vector<int>& decode_array, unsigned int converting_number )
{


    //cout << "Converting a number: " << hex << converting_number << endl;

    unsigned int auxiliar_variable = 0x0;

    unsigned int mask = 0xf;

    int i = 8;

    for (i = 0; i < 8; i++)
    {
        auxiliar_variable = 0x0;

        auxiliar_variable = (converting_number >> (i*4)) & mask;

        //vector<int> tmp_vector;
        //vector<int>& tmp_vector_reference = tmp_vector;

        DecodeSum(decode_array, auxiliar_variable, i);

        //~ int j = 0;

        //~ for (j = 0; j < decode_array.size(); i++)
        //~ {
            //~ cout << dec
        //~ }
    }

}

void MainWindow::HumanReadableError(int error_code)
{
    if (error_code == 1)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase1Error");
    }
    else if (error_code == 2)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase2Error");
    }
    else if (error_code == 3)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase3Error");
    }
    else if (error_code == 4)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase4Error");
    }
    else if (error_code == 5)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase5Error");
    }
    else if (error_code == 6)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase6Error");
    }
    else if (error_code == 7)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase7Error");
    }
    else if (error_code == 8)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACPhase8Error");
    }
    else if (error_code == 9)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome1Error");
    }
    else if (error_code == 10)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome2Error");
    }
    else if (error_code == 11)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome3Error");
    }
    else if (error_code == 12)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome4Error");
    }
    else if (error_code == 13)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome5Error");
    }
    else if (error_code == 14)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome6Error");
    }
    else if (error_code == 15)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome7Error");
    }
    else if (error_code == 16)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACHome8Error");
    }
    else if (error_code == 17)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier1Error");
    }
    else if (error_code == 18)
    {
        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier2Error");
    }
    else if (error_code == 19)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier3Error");
    }
    else if (error_code == 20)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier4Error");
    }
    else if (error_code == 21)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier5Error");
    }
    else if (error_code == 22)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier6Error");
    }
    else if (error_code == 23)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier7Error");
    }
    else if (error_code == 24)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAmplifier8Error");
    }
    else if (error_code == 25)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera1Error");
    }
    else if (error_code == 26)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera2Error");
    }
    else if (error_code == 27)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera3Error");
    }
    else if (error_code == 28)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera4Error");
    }
    else if (error_code == 29)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera5Error");
    }
    else if (error_code == 30)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera6Error");
    }
    else if (error_code == 31)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera7Error");
    }
    else if (error_code == 32)
    {
         AppendMessageToQtextEdit(ui->textEdit_BaseCase, "PMACAltera8Error");
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    decoding_error = false;

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

    if (decoding_error == true)
    {

        QString data_string(data);

        AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Decodifico");

        vector<int> decode_array;

        vector<int>& decode_array_reference = decode_array;

        unsigned int converting_number =  data_string.toUInt();

        DecodeErrors(decode_array_reference, converting_number);

        int i = 0;

        for (i = 0; i < decode_array_reference.size(); i++)
        {
            //cout << "Errore al motore: " <<  dec << decode_array_reference[i] << endl;
            HumanReadableError(decode_array_reference[i]);
        }

        decoding_error == false;
    }

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

    if (ui->lineEdit_BaseCase->text() == "&2P91" || ui->lineEdit_BaseCase->text() == "&2p91")
    {
        decoding_error = true;
    }
    else
    {
        decoding_error = false;
    }

    AppendMessageToQtextEdit(ui->textEdit_BaseCase, "Command sent: " + ui->lineEdit_BaseCase->text());

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
