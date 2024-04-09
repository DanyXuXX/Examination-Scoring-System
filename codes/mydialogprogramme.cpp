#include "mydialogprogramme.h"
#include "ui_mydialogprogramme.h"

MyDialogProgramme::MyDialogProgramme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialogProgramme)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");

    connect(ui->pushButton_yes,SIGNAL(clicked(bool)),this,SLOT(log()));
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

MyDialogProgramme::~MyDialogProgramme()
{
    delete ui;
}

void MyDialogProgramme::log()
{
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);//密码隐藏为符号
    if(ui->lineEdit_name->text().trimmed()==tr("xdy")&&ui->lineEdit_password->text()==tr("biancheng"))
    {
        accept();//接受登录
        m_rewriteprogramme =new RewriteProgramme(this);
        m_rewriteprogramme->show();
    }
    else
    {
        QMessageBox::critical(0 ,"警告" , "用户名或密码不正确",
                              QMessageBox::Ok | QMessageBox::Default , 0 ,  0 );
        //清空密码栏
        ui->lineEdit_password->clear();
        ui->lineEdit_password->setFocus();//光标定位在password一栏
    }
}
