#include "readprogramme.h"
#include "ui_readprogramme.h"

ReadProgramme::ReadProgramme(QString number,QString answer1,QString answer2,QString answer3,QString answer4,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReadProgramme)
   ,m_number(number+1)
   ,m_answer1(answer1)
   ,m_answer2(answer2)
   ,m_answer3(answer3)
   ,m_answer4(answer4)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("编程题--学生答题"));//改窗口名字
    //在界面上显示学号，不可修改
    ui->lineEdit_number->setText(m_number);
    ui->lineEdit_number->setReadOnly(true);
    ui->textEdit_answer->setText(m_answer1);
    ui->textEdit_answer->setReadOnly(true);
    ui->pushButton_last->hide();
}

ReadProgramme::~ReadProgramme()
{
    delete ui;
}

void ReadProgramme::on_pushButton_next_clicked()
{
    if(ui->comboBox_QuestinoNumber->currentIndex()==0)
    {
        ui->textEdit_answer->setText(m_answer2);
        ui->comboBox_QuestinoNumber->setCurrentIndex(1);
        ui->pushButton_last->show();
        return;
    }
    if(ui->comboBox_QuestinoNumber->currentIndex()==1)
    {
        ui->textEdit_answer->setText(m_answer3);
        ui->comboBox_QuestinoNumber->setCurrentIndex(2);
        return;
    }
    if(ui->comboBox_QuestinoNumber->currentIndex()==2)
    {
        ui->textEdit_answer->setText(m_answer4);
        ui->comboBox_QuestinoNumber->setCurrentIndex(3);
        ui->pushButton_next->hide();
        return;
    }
}

void ReadProgramme::on_pushButton_last_clicked()
{
    if(ui->comboBox_QuestinoNumber->currentIndex()==0)
    {
        ui->pushButton_last->hide();
        return;
    }
    if(ui->comboBox_QuestinoNumber->currentIndex()==1)
    {
        ui->textEdit_answer->setText(m_answer1);
        ui->comboBox_QuestinoNumber->setCurrentIndex(0);
        return;
    }
    if(ui->comboBox_QuestinoNumber->currentIndex()==2)
    {
        ui->textEdit_answer->setText(m_answer2);
        ui->comboBox_QuestinoNumber->setCurrentIndex(1);
        return;
    }
    if(ui->comboBox_QuestinoNumber->currentIndex()==3)
    {
        ui->textEdit_answer->setText(m_answer3);
        ui->comboBox_QuestinoNumber->setCurrentIndex(2);
        ui->pushButton_last->show();
        return;
    }
}

void ReadProgramme::on_comboBox_QuestinoNumber_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->textEdit_answer->setText(m_answer1);
        ui->pushButton_last->hide();
        ui->pushButton_next->show();
    }
    if(index==1)
    {
        ui->textEdit_answer->setText(m_answer2);
        ui->pushButton_last->show();
        ui->pushButton_next->show();
    }
    if(index==2)
    {
        ui->textEdit_answer->setText(m_answer3);
        ui->pushButton_last->show();
        ui->pushButton_next->show();
    }
    if(index==3)
    {
        ui->textEdit_answer->setText(m_answer4);
        ui->pushButton_last->show();
        ui->pushButton_next->hide();
    }
}
