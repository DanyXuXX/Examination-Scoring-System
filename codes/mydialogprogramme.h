#ifndef MYDIALOGPROGRAMME_H
#define MYDIALOGPROGRAMME_H

#include <QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QMessageBox>
#include"rewriteprogramme.h"

namespace Ui {
class MyDialogProgramme;
}

class MyDialogProgramme : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialogProgramme(QWidget *parent = 0);
    ~MyDialogProgramme();

private slots:
    void log();

private:
    Ui::MyDialogProgramme *ui;
    RewriteProgramme *m_rewriteprogramme;
};

#endif // MYDIALOGPROGRAMME_H
