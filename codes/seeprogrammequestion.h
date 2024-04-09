#ifndef SEEPROGRAMMEQUESTION_H
#define SEEPROGRAMMEQUESTION_H

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
class SeeProgrammeQuestion;
}

class SeeProgrammeQuestion : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeeProgrammeQuestion(QWidget *parent = 0);
    ~SeeProgrammeQuestion();

private:
    Ui::SeeProgrammeQuestion *ui;
};

#endif // SEEPROGRAMMEQUESTION_H
