#ifndef READCHANGE_H
#define READCHANGE_H

#include <QMainWindow>
#include <QDebug>
#include <QString>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QFileDialog>
#include <QStringList>
#include <QDialog>


namespace Ui {
class ReadChange;
}

class ReadChange : public QMainWindow
{
    Q_OBJECT


public:
    explicit ReadChange(QString,QString,QString,QString,QString,QWidget *parent = 0);
    ~ReadChange();

private slots:

    void on_comboBox_QuestinoNumber_currentIndexChanged(int index);

    void on_pushButton_next_clicked();

    void on_pushButton_last_clicked();

private:
    Ui::ReadChange *ui;
    QString m_number,m_answer1,m_answer2,m_answer3,m_answer4;
};

#endif // READCHANGE_H
