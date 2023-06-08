
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void make();
    void display(QVector<QVector <QChar>> some);
private:
    Ui::MainWindow *ui;
    QString label_text="";
    QVector <QChar> persons = {'1','2','3','4','5'};
    QVector <QChar> automob = {' ',' ',' ',' ',' '};
    QVector <QChar> variant;
    QVector<QVector <QChar>> all;
    int free_size = 5;
    int free_pers = 5;
};

#endif // MAINWINDOW_H
