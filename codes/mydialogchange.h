#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QMessageBox>
#include"rewritechange.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void log();

private:
    Ui::Dialog *ui;
    RewriteChange *m_rewritechange;
};

#endif // DIALOG_H
