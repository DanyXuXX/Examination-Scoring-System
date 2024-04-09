#ifndef REWRITECHANGE_H
#define REWRITECHANGE_H

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
class RewriteChange;
}

class RewriteChange : public QMainWindow
{
    Q_OBJECT

public:
    explicit RewriteChange(QWidget *parent = 0);
    ~RewriteChange();

private slots:
    void on_pushButton_finish_clicked();

private:
    Ui::RewriteChange *ui;
};

#endif // REWRITECHANGE_H
