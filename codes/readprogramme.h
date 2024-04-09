#ifndef READPROGRAMME_H
#define READPROGRAMME_H

#include <QMainWindow>

namespace Ui {
class ReadProgramme;
}

class ReadProgramme : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReadProgramme(QString,QString,QString,QString,QString, QWidget *parent = 0);
    ~ReadProgramme();

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_last_clicked();

    void on_comboBox_QuestinoNumber_currentIndexChanged(int index);

private:
    Ui::ReadProgramme *ui;
     QString m_number,m_answer1,m_answer2,m_answer3,m_answer4;
};

#endif // READPROGRAMME_H
