#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QApplication>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QDebug>
#include<QString>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QFileDialog>

#include"readchange.h"//子窗口头文件
#include"readprogramme.h"
#include"seechangequestion.h"
#include"seeprogrammequestion.h"
#include"mydialogchange.h"
#include"mydialogprogramme.h"

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    void ShowTotalScore();
    int getTotalScore();
    int getNumber();

private slots:
    void on_pushButton_NewPaper_clicked();//判新卷

    void on_pushButton_TotalScore_clicked();//计算总分

    void createExec();
    void absent();


    void on_pushButton_FinishPaper_clicked();


    void on_pushButton_OpenChange_clicked();

    void on_pushButton_OpenProgramme_clicked();

    void on_action_SeeChange_triggered();

    void on_action_SeeProgramme_triggered();

    void on_action_change_triggered();

    void on_action_programme_triggered();

private:
    Ui::MyMainWindow *ui;
    ReadChange *m_readchange;
    ReadProgramme *m_readprogramme;
    SeeChangeQuestion *m_seechangeQ;
    SeeProgrammeQuestion *m_seeprogrammeQ;
    Dialog *m_dialog;
    MyDialogProgramme *m_dialogprogramme;
};

#endif // MYMAINWINDOW_H
