#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int rowCount;
    int colCount;


private slots:
    void on_actionOpen_triggered();
    void on_actionAdd_triggered();
    void on_actionSave_triggered();
    void on_actionDel_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
