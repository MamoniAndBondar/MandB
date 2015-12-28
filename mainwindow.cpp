#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include "dialog.h"
#include "dialogdel.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString name = QFileDialog::getOpenFileName(this, "Открыть", "data.txt", QString("Текстовые файлы(*.txt);;Все файлы(*)"));
    QFile file(name);
    file.open(QIODevice::ReadOnly);
    QString str;
    QStringList list;
    rowCount = 0;
    colCount = 0;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8);
    list << "ID" << "Фамилия" << "Имя" << "Отчество" << "Пол" << "Возраст" << "Рост" << "Вес";
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(60);
    ui->tableWidget->horizontalHeader()->resizeSection(0,30);
    ui->tableWidget->horizontalHeader()->resizeSection(1,100);
    ui->tableWidget->horizontalHeader()->resizeSection(2,100);
    ui->tableWidget->horizontalHeader()->resizeSection(3,100);

    while (!file.atEnd())
    {
        str = file.readLine();
        ui->tableWidget->insertRow(rowCount);
        list = str.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        for (int i = 0; i <list.size(); ++i)
        {
                QTableWidgetItem* item = new QTableWidgetItem(QString(list[i]));
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(rowCount, i, item);
        }
         rowCount++;
    }
    colCount = ui->tableWidget->columnCount();
}

void MainWindow::on_actionAdd_triggered()
{
    Dialog dlg(this);
    if (dlg.exec()==QDialog::Accepted)
    {
        QStringList list = dlg.TTT();
        qDebug() << list;
        ui->tableWidget->insertRow(rowCount);
        for (int i = 0; i <list.size(); ++i)
        {
            QTableWidgetItem* item = new QTableWidgetItem(QString(list[i]));
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(rowCount, i, item);
        }
        rowCount++;
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString list;
    for (int i = 0; i <rowCount; ++i)
    {
        for (int j = 0; j <colCount; ++j)
        {
            list += ui->tableWidget->item(i,j)->text();
            list += " ";
        }
        list += "\n";
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", QString(), QString("Текстовые файлы (*.txt);;Все файлы (*.*)") );
    QFile rezFile;
    if (!fileName.isEmpty())
        {
            rezFile.setFileName(fileName);
            rezFile.open(QIODevice::WriteOnly|QIODevice::Text);
     // открываем файл
            QTextStream out(&rezFile);
            out << list;
            rezFile.close();
        }
}

void MainWindow::on_actionDel_triggered()
{
    DialogDel dlg(this);
    if (dlg.exec()==QDialog::Accepted)
    {
       for (int i = 0; i < colCount; ++i)
       {
           QTableWidgetItem* item = new QTableWidgetItem(" ");
           ui->tableWidget->setItem(dlg.Del(), i, item);
       }
    }
}
