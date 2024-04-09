#include "seeprogrammequestion.h"
#include "ui_seeprogrammequestion.h"

SeeProgrammeQuestion::SeeProgrammeQuestion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeeProgrammeQuestion)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("编程题试题"));//改窗口名字

    ui->textEdit_Q1->setReadOnly(true);
    ui->textEdit_Q2->setReadOnly(true);
    ui->textEdit_Q3->setReadOnly(true);
    ui->textEdit_Q4->setReadOnly(true);

    //打开改错题文件
    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    dir.cdUp();//返回上一级路径
    QFile m_file(dir.absolutePath()+"./Test/SeeProgrammeQuestion.json");
    m_file.open(QIODevice::ReadOnly);//|QIODevice::Text

    QByteArray m_alldata=m_file.readAll();
    m_file.close();

    QJsonParseError m_error;
    QJsonDocument m_doc(QJsonDocument::fromJson(m_alldata,&m_error));
    if(m_error.error==QJsonParseError::NoError)//解析是否出现错误
    {
        if(m_doc.isArray())//数组判断
        {
            QJsonArray m_array=m_doc.array();//转数组

            for(int i=0;i<m_array.count();i++)
            {
                QJsonValue m_value=m_array.at(i);

                if(m_value.type()==QJsonValue::Object)
                {
                    QJsonObject m_obj=m_value.toObject();
                    QString Q1=m_obj.value("Q1").toString();
                    QString Q2=m_obj.value("Q2").toString();
                    QString Q3=m_obj.value("Q3").toString();
                    QString Q4=m_obj.value("Q4").toString();
                    ui->textEdit_Q1->setText(Q1);
                    ui->textEdit_Q2->setText(Q2);
                    ui->textEdit_Q3->setText(Q3);
                    ui->textEdit_Q4->setText(Q4);
                }
            }
        }
    }
}

SeeProgrammeQuestion::~SeeProgrammeQuestion()
{
    delete ui;
}
