#include "mydialogchange.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    
    connect(ui->pushButton_yes,SIGNAL(clicked(bool)),this,SLOT(log()));
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::log()
{
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);//密码隐藏为符号
    if(ui->lineEdit_name->text().trimmed()==tr("xdy")&&ui->lineEdit_password->text()==tr("gaicuo"))
    {
        accept();//接受登录
        m_rewritechange =new RewriteChange(this);
        m_rewritechange->show();
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
