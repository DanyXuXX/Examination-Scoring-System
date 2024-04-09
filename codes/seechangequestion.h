#ifndef SEECHANGEQUESTION_H
#define SEECHANGEQUESTION_H

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

namespace Ui {
class SeeChangeQuestion;
}

class SeeChangeQuestion : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeeChangeQuestion(QWidget *parent = 0);
    ~SeeChangeQuestion();

private:
    Ui::SeeChangeQuestion *ui;
};

#endif // SEECHANGEQUESTION_H
