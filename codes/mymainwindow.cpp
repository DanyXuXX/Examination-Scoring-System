#include "mymainwindow.h"
#include "ui_mymainwindow.h"
//#include<QDialog>
#include<QMessageBox>
#include<QFile>

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)//constructor
{
    ui->setupUi(this);
    this->setWindowTitle(QString("考试判卷系统"));//改主窗口名字

    //总分&输入成绩设置为只能输入数字
    ui->lineEdit_TotalScore->setValidator(new QIntValidator);
    ui->lineEdit_Change1->setValidator(new QIntValidator);
    ui->lineEdit_Change2->setValidator(new QIntValidator);
    ui->lineEdit_Change3->setValidator(new QIntValidator);
    ui->lineEdit_Change4->setValidator(new QIntValidator);
    ui->lineEdit_Programme1->setValidator(new QIntValidator);
    ui->lineEdit_Programme2->setValidator(new QIntValidator);
    ui->lineEdit_Programme3->setValidator(new QIntValidator);
    ui->lineEdit_Programme4->setValidator(new QIntValidator);
    ui->lineEdit_Number->setValidator(new QIntValidator);

    //文件名显示为只读
    ui->lineEdit_DocName->setReadOnly(true);
}


MyMainWindow::~MyMainWindow()//destructor
{
    delete ui;
    //delete invalidator
}

void MyMainWindow::on_pushButton_NewPaper_clicked()//判新卷
{
    ui->lineEdit_Change1->clear();
    ui->lineEdit_Change2->clear();
    ui->lineEdit_Change3->clear();
    ui->lineEdit_Change4->clear();
    ui->lineEdit_Number->clear();

    ui->lineEdit_Programme1->clear();
    ui->lineEdit_Programme2->clear();
    ui->lineEdit_Programme3->clear();
    ui->lineEdit_Programme4->clear();
    ui->lineEdit_TotalScore->clear();

    m_readchange->close();
    m_readprogramme->close();
    m_seechangeQ->close();
    m_seeprogrammeQ->close();
    m_dialog->close();
    m_dialogprogramme->close();
}


void MyMainWindow::on_pushButton_TotalScore_clicked()//计算总分
{

    if((ui->lineEdit_TotalScore->text()).toInt()==-1)
    {
        this->MyMainWindow::absent();
        return;
    }

    //QString类型转换为int类型
    unsigned int t_score;
    QString t_sc1=ui->lineEdit_Change1->text(); int t_ic1=t_sc1.toInt();
    QString t_sc2=ui->lineEdit_Change2->text(); int t_ic2=t_sc2.toInt();
    QString t_sc3=ui->lineEdit_Change3->text(); int t_ic3=t_sc3.toInt();
    QString t_sc4=ui->lineEdit_Change4->text(); int t_ic4=t_sc4.toInt();

    QString t_sp1=ui->lineEdit_Programme1->text(); int t_ip1=t_sp1.toInt();
    QString t_sp2=ui->lineEdit_Programme2->text(); int t_ip2=t_sp2.toInt();
    QString t_sp3=ui->lineEdit_Programme3->text(); int t_ip3=t_sp3.toInt();
    QString t_sp4=ui->lineEdit_Programme4->text(); int t_ip4=t_sp4.toInt();
    if(t_sc1.isEmpty()||t_sc2.isEmpty()||t_sc3.isEmpty()||t_sc4.isEmpty()||t_sp1.isEmpty()||t_sp2.isEmpty()||t_sp3.isEmpty()||t_sp4.isEmpty())
    {
        QMessageBox::critical(0 ,"警告" , "得分栏不能为空",
                              QMessageBox::Ok | QMessageBox::Default , 0 ,  0 );
        return;
    }

    t_score=t_ic1+t_ic2+t_ic3+t_ic4+t_ip1+t_ip2+t_ip3+t_ip4;

    if(t_score>30)
    {
        //槽函数中不用再用connect关联，函数默认自动关联
        //connect(ui->pushButton_TotalScore,&QPushButton::pressed,this,&MyMainWindow::createExec);
        this->MyMainWindow::createExec();

    }
    else if(t_score<=30)
    {
        this->MyMainWindow::ShowTotalScore();
    }
}

void MyMainWindow:: createExec()//总分超30警告框
{
    //QDialog *d=new QDialog;

    QMessageBox::critical(0 ,"注意" , "总分超过30！",
                          QMessageBox::Ok | QMessageBox::Default , 0 ,  0 );
    //d->exec();
    // d->setAttribute(Qt::WA_DeleteOnClose);//关闭时手动释放内存
}

void MyMainWindow::absent()//缺考提示框
{
    QMessageBox::information(0,"提示","考生缺考！",QMessageBox::Ok|QMessageBox::Default,0,0);
}

void MyMainWindow:: ShowTotalScore()//计算总分
{   
    unsigned int t_score;//（Qstring和int互相转换）
    QString t_sc1=ui->lineEdit_Change1->text(); int t_ic1=t_sc1.toInt();
    QString t_sc2=ui->lineEdit_Change2->text(); int t_ic2=t_sc2.toInt();
    QString t_sc3=ui->lineEdit_Change3->text(); int t_ic3=t_sc3.toInt();
    QString t_sc4=ui->lineEdit_Change4->text(); int t_ic4=t_sc4.toInt();

    QString t_sp1=ui->lineEdit_Programme1->text(); int t_ip1=t_sp1.toInt();
    QString t_sp2=ui->lineEdit_Programme2->text(); int t_ip2=t_sp2.toInt();
    QString t_sp3=ui->lineEdit_Programme3->text(); int t_ip3=t_sp3.toInt();
    QString t_sp4=ui->lineEdit_Programme4->text(); int t_ip4=t_sp4.toInt();

    t_score=t_ic1+t_ic2+t_ic3+t_ic4+t_ip1+t_ip2+t_ip3+t_ip4;
    QString temp = QString::number(t_score, 10);
    ui->lineEdit_TotalScore->setText(temp);
    ui->lineEdit_TotalScore->show();
}

int MyMainWindow::getTotalScore()
{
    QString t= ui->lineEdit_TotalScore->text();
    int r=t.toInt();
    return r;
}
int MyMainWindow::getNumber()//jsonobject.insert功能要求
{
    QString t= ui->lineEdit_Number->text();
    int r=t.toInt();
    return r;
}

void MyMainWindow::on_pushButton_FinishPaper_clicked()//本卷判毕
{
    QString t=ui->lineEdit_TotalScore->text();
    QString num=ui->lineEdit_Number->text();
    int int_readnum=num.toInt();
    if(t.isEmpty())
    {
        QMessageBox::critical(0 ,"注意" , "未计算总分！",
                              QMessageBox::Ok | QMessageBox::Default , 0 ,  0 );
        return;//要不然空的内容就直接写进文档了
    }

    QString t_sc1=ui->lineEdit_Change1->text();
    QString t_sc2=ui->lineEdit_Change2->text();
    QString t_sc3=ui->lineEdit_Change3->text();
    QString t_sc4=ui->lineEdit_Change4->text();

    QString t_sp1=ui->lineEdit_Programme1->text();
    QString t_sp2=ui->lineEdit_Programme2->text();
    QString t_sp3=ui->lineEdit_Programme3->text();
    QString t_sp4=ui->lineEdit_Programme4->text();
    if(t_sc1.isEmpty()||t_sc2.isEmpty()||t_sc3.isEmpty()||t_sc4.isEmpty()
            ||t_sp1.isEmpty()||t_sp2.isEmpty()||t_sp3.isEmpty()||t_sp4.isEmpty())
    {
        QMessageBox::critical(0 ,"注意" , "不允许直接输入分数",
                              QMessageBox::Ok | QMessageBox::Default , 0 ,  0 );
        return;
    }
    if(t==-1)
    {
        QMessageBox::information(0,"提示","考生缺考！",QMessageBox::Ok|QMessageBox::Default,0,0);
    }
    // 以读写方式打开主目录下的Grades.json文件，文件不存在就自动创建
    //QFile m_file(QDir::currentPath() + "/Grades.json");

    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    dir.cdUp();//返回上一级路径
    QFile m_file(dir.absolutePath()+"./Test/Grades.json");
    m_file.open(QIODevice::ReadWrite);//|QIODevice::Text

    if(!m_file.open(QIODevice::ReadWrite))
    {
        qDebug() << "File open error";
    }

    ui->lineEdit_DocName->setText("Grades.json");
    QByteArray m_alldata=m_file.readAll();
    QJsonParseError m_error;
    QJsonDocument m_doc(QJsonDocument::fromJson(m_alldata,&m_error));

    // 使用QJsonArray添加值，并写入文件
    QJsonArray m_array;
    // QJsonDocument m_jsondoc;
    if(m_doc.isNull())//第一次新建文件的情况
    {
        qDebug()<<"isnull";
        // 使用QJsonArray添加值，并写入文件
        QJsonObject m_jsonObject;
        m_jsonObject.insert("Number", MyMainWindow::getNumber());
        m_jsonObject.insert("Score", MyMainWindow::getTotalScore());
        m_array.append(m_jsonObject);

        m_doc.setArray(m_array);

        m_file.write(m_doc.toJson());
        m_file.close();

        //清空学号栏、总分栏和各项得分栏中的数据
        ui->lineEdit_Change1->clear();
        ui->lineEdit_Change2->clear();
        ui->lineEdit_Change3->clear();
        ui->lineEdit_Change4->clear();
        ui->lineEdit_Number->clear();

        ui->lineEdit_Programme1->clear();
        ui->lineEdit_Programme2->clear();
        ui->lineEdit_Programme3->clear();
        ui->lineEdit_Programme4->clear();
        ui->lineEdit_TotalScore->clear();

        QString NextNumber = QString::number(int_readnum+1, 10);
        ui->lineEdit_Number->setText(NextNumber);//自动换成下一个学生的学号
        return;
    }


    m_file.close();
    if(!m_doc.isNull()&&m_error.error==QJsonParseError::NoError)//解析是否出现错误
    {
        if(m_doc.isArray())//数组判断
        {
            m_array=m_doc.array();//转数组

            for(QJsonArray::iterator it=m_array.begin();it!=m_array.end();it++)
            {
                QJsonValue m_value=m_array.at(0);
                qDebug()<<"in iterator";

                if(m_value.type()==QJsonValue::Object)//符合对象的数据类型
                {
                    QJsonObject m_obj=it[0].toObject();//i[0]表示迭代器所在的位置
                    int jsonnum=m_obj.value("Number").toInt();
                    qDebug()<<int_readnum<<"   "<<jsonnum;

                    //修改文件中的数值
                    //输入的学号==json文件中保存的学号
                    if(int_readnum==jsonnum)
                    {

                        m_obj.insert("Score",MyMainWindow::getTotalScore());
                        it[0]=m_obj;
                        qDebug()<<it[0];

                        //重新打开一遍
                        //重复学号的成绩会被重写
                        m_file.open(QIODevice::WriteOnly);
                        m_file.flush();
                        m_doc.setArray(m_array);
                        m_file.write(m_doc.toJson());
                        m_file.close();
                        qDebug() << "Have changed and written to file.";

                        //清空学号栏、总分栏和各项得分栏中的数据
                        ui->lineEdit_Change1->clear();
                        ui->lineEdit_Change2->clear();
                        ui->lineEdit_Change3->clear();
                        ui->lineEdit_Change4->clear();
                        ui->lineEdit_Number->clear();

                        ui->lineEdit_Programme1->clear();
                        ui->lineEdit_Programme2->clear();
                        ui->lineEdit_Programme3->clear();
                        ui->lineEdit_Programme4->clear();
                        ui->lineEdit_TotalScore->clear();

                        QString NextNumber = QString::number(int_readnum+1, 10);
                        ui->lineEdit_Number->setText(NextNumber);//自动换成下一个学生的学号
                        return;
                    }
                }
            }
            //如果是新加的学号，定位到文件尾
            QJsonValue m_value=m_array.at(0);
            QJsonObject m_obj=m_value.toObject();
            // int num=m_obj.value("Number").toInt();
            // int sc=m_obj.value("Score").toInt();


            m_obj.insert("Number", MyMainWindow::getNumber());
            m_obj.insert("Score", MyMainWindow::getTotalScore());
            m_array.append((m_obj));

            //QJsonDocument m_doc;
            m_doc.setArray(m_array);
            //重新打开一遍
            //重复学号的成绩会被重写
            m_file.open(QIODevice::WriteOnly);
            m_file.write(m_doc.toJson());
            m_file.close();
            qDebug() << "Have added and written to file.";

            //清空学号栏、总分栏和各项得分栏中的数据
            ui->lineEdit_Change1->clear();
            ui->lineEdit_Change2->clear();
            ui->lineEdit_Change3->clear();
            ui->lineEdit_Change4->clear();
            ui->lineEdit_Number->clear();

            ui->lineEdit_Programme1->clear();
            ui->lineEdit_Programme2->clear();
            ui->lineEdit_Programme3->clear();
            ui->lineEdit_Programme4->clear();
            ui->lineEdit_TotalScore->clear();

            QString NextNumber = QString::number(int_readnum+1, 10);
            ui->lineEdit_Number->setText(NextNumber);//自动换成下一个学生的学号
        }
    }
}


void MyMainWindow::on_pushButton_OpenChange_clicked()//打开改错题文件
{
    QString qstring_readnumber=ui->lineEdit_Number->text();
    int int_readnum=qstring_readnumber.toInt();
    if(qstring_readnumber.isEmpty())
    {
        QMessageBox::information(0,"提示","请输入学号",QMessageBox::Ok|QMessageBox::Default,0,0);
        return;
    }

    //打开指定文件
    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    dir.cdUp();//返回上一级路径
    QFile m_file(dir.absolutePath()+"./Test/ReadChange.json");
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
                    int num=m_obj.value("number").toInt();
                    QString answer1=m_obj.value("answer1").toString();
                    QString answer2=m_obj.value("answer2").toString();
                    QString answer3=m_obj.value("answer3").toString();
                    QString answer4=m_obj.value("answer4").toString();

                    //防止出现意外关闭界面后再打开变成另一个学生的答题情况
                    //只有在输入的学号和json文件中的学号能对上时才显示相应答题情况
                    if(int_readnum==num)//输入的学号==json文件中保存的学号
                    {
                        m_readchange = new ReadChange(QString::number(num),answer1,answer2,answer3,answer4);
                        m_readchange->show();
                        return;
                    }
                }
            }
        }
    }
    QMessageBox::information(0,"提示","此学号没有对应答题情况",QMessageBox::Ok|QMessageBox::Default,0,0);
}

void MyMainWindow::on_pushButton_OpenProgramme_clicked()//打开编程题文件
{
    QString qstring_readnumber=ui->lineEdit_Number->text();
    int int_readnum=qstring_readnumber.toInt();
    if(qstring_readnumber.isEmpty())
    {
        QMessageBox::information(0,"提示","请输入学号",QMessageBox::Ok|QMessageBox::Default,0,0);
        return;
    }

    //打开指定文件
    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    dir.cdUp();//返回上一级路径
    QFile m_file(dir.absolutePath()+"./Test/ReadProgramme.json");
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
                    int num=m_obj.value("number").toInt();
                    QString answer1=m_obj.value("answer1").toString();
                    QString answer2=m_obj.value("answer2").toString();
                    QString answer3=m_obj.value("answer3").toString();
                    QString answer4=m_obj.value("answer4").toString();

                    //防止出现意外关闭界面后再打开变成另一个学生的答题情况
                    //只有在输入的学号和json文件中的学号能对上时才显示相应答题情况
                    if(int_readnum==num)//输入的学号==json文件中保存的学号
                    {
                        m_readprogramme = new ReadProgramme(QString::number(num),answer1,answer2,answer3,answer4);
                        m_readprogramme->show();
                        return;
                    }
                }
            }
        }
    }
    QMessageBox::information(0,"提示","此学号没有对应答题情况",QMessageBox::Ok|QMessageBox::Default,0,0);
}


void MyMainWindow::on_action_SeeChange_triggered()
{
    m_seechangeQ=new SeeChangeQuestion(this);
    m_seechangeQ->show();
}

void MyMainWindow::on_action_SeeProgramme_triggered()
{
    m_seeprogrammeQ=new SeeProgrammeQuestion(this);
    m_seeprogrammeQ->show();
}

void MyMainWindow::on_action_change_triggered()
{
    m_dialog=new Dialog(this);
    m_dialog->exec();
}

void MyMainWindow::on_action_programme_triggered()
{
    m_dialogprogramme=new MyDialogProgramme(this);
    m_dialogprogramme->exec();
}
