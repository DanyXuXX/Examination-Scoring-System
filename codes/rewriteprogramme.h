#ifndef REWRITEPROGRAMME_H
#define REWRITEPROGRAMME_H

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
#include<QMessageBox>

namespace Ui {
class RewriteProgramme;
}

class RewriteProgramme : public QMainWindow
{
    Q_OBJECT

public:
    explicit RewriteProgramme(QWidget *parent = 0);
    ~RewriteProgramme();

private slots:
    void on_pushButton_finish_clicked();

private:
    Ui::RewriteProgramme *ui;
};

#endif // REWRITEPROGRAMME_H
