#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
QStringList Dialog::TTT()
{
  QStringList list;
  list << ui->lineEdit->text() << ui->lineEdit_2->text() << ui->lineEdit_3->text() << ui->lineEdit_4->text() << ui->lineEdit_5->text() << ui->lineEdit_6->text() << ui->lineEdit_7->text() << ui->lineEdit_8->text();
  return list;
}

