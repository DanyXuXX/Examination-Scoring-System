#include "rewriteprogramme.h"
#include "ui_rewriteprogramme.h"

RewriteProgramme::RewriteProgramme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RewriteProgramme)
{
    ui->setupUi(this);
    this->setWindowTitle("修改编程题试卷");

    //打开改错题文件
    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    dir.cdUp();//返回上一级路径
    QFile m_file(dir.absolutePath()+"./Test/SeeProgrammeQuestion.json");
    m_file.open(QIODevice::ReadWrite);//|QIODevice::Text

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

RewriteProgramme::~RewriteProgramme()
{
    delete ui;
}

void RewriteProgramme::on_pushButton_finish_clicked()
{
    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    dir.cdUp();//返回上一级路径
    QFile m_file(dir.absolutePath()+"./Test/SeeProgrammeQuestion.json");
    m_file.open(QIODevice::ReadOnly);//|QIODevice::Text
    if(!m_file.open(QIODevice::ReadWrite))
    {
        qDebug() << "File open error";
    }

    // 使用QJsonArray添加值，并写入文件
    static QJsonArray m_jsonArray;

    QByteArray m_alldata=m_file.readAll();
    m_file.close();

    QJsonParseError m_error;
    QJsonDocument m_doc(QJsonDocument::fromJson(m_alldata,&m_error));
    if(m_error.error==QJsonParseError::NoError)//解析是否出现错误
    {
        if(m_doc.isArray())//数组判断
        {
            QJsonArray m_array=m_doc.array();//转数组

            for(QJsonArray::iterator i=m_array.begin();i!=m_array.end();i++)
            {
                QJsonValue m_value=m_array.at(0);

                if(m_value.type()==QJsonValue::Object)//符合对象的数据类型
                {
                    QJsonObject m_obj=i[0].toObject();
                    m_obj.insert("Q1",ui->textEdit_Q1->toPlainText());
                    m_obj.insert("Q2",ui->textEdit_Q2->toPlainText());
                    m_obj.insert("Q3",ui->textEdit_Q3->toPlainText());
                    m_obj.insert("Q4",ui->textEdit_Q4->toPlainText());
                    i[0]=m_obj;
                    qDebug()<<i[0];
                    int num=m_obj.value("Number").toInt();
                    int sc=m_obj.value("Score").toInt();

                    //修改文件中的数值
                    //重新打开一遍
                    //重复学号的成绩会被重写
                    m_file.open(QIODevice::WriteOnly);
                    m_file.flush();
                    m_doc.setArray(m_array);
                    m_file.write(m_doc.toJson());
                    m_file.close();
                    qDebug() << "Have changed Q and written to file.";
                }
            }
        }
    }
    this->close();
    QMessageBox::about(NULL, "About", "试卷修改成功");
}
