
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    make();
}
void MainWindow::make()
{
    QVector<QVector <QChar>> newall;
    for(int i=0; i<free_size ; i++)
        {
            variant=automob;
            variant[i]=persons[0];
            all.push_back(variant);
        }
    persons.erase(persons.begin());
    for (int i=0; i<free_size-1; i++)
    {
        newall.clear();
        for(int j=0; j<all.size(); j++)
            {
                for(int k=0; k<free_size; k++)
                {
                    variant=all[j];
                    if(variant[k].isSpace())
                    {
                        variant[k]=persons[0];
                        newall.push_back(variant);
                    }
                }
            }
        persons.erase(persons.begin());
        all=newall;
    }
    display(newall);
    return;
}
void MainWindow::display(QVector<QVector <QChar>> all)
{
    int count=0;
    for(int i=0; i<all.size(); i++)
    {
        for(int j=0; j<all[i].size(); j++)
        {
            label_text+= all[i][j];
        }
        label_text+="\t";
        count++;
        if (count%20==0)
            {label_text+="\n";}
    }
    ui->label->setText(label_text);
}
MainWindow::~MainWindow()
{
    delete ui;
}
/*

*/
/*
 * вільних місць 5
1
  1
    1
      1
        1
варіантів 5
вільних місць 4
1 2
1   2
1     2
1       2
2 1
  1 2
  1   2
  1     2
2   1
  2 1
    1 2
    1   2
2     1
  2   1
    2 1
      1 2
2       1
  2     1
    2   1
      2 1
варіантів 20
1 2 3
1 3 2
1 3   2
1 3     2
*/
/*
int MainWindow::numberC(QVector <QChar> persons, int free, QString output, int auto_size, int i)
{
    if (free==0)
    {
        label_text = ui->label->text();
        label_text+=output;
        label_text+='\n';
        ui->label->setText(label_text);
        i=0;
        return 120;
    }
    for (; i<persons.size();)
    {
        QString appended = output+persons[i];
        numberC(persons, free-1, appended, auto_size, ++i);
    }
}
void MainWindow::numberV(QVector <QChar> persons, int size)
{
    for (int i=size; i<size+1; i++)
    {
        int ret= numberC(persons, i, "", size, 0);
    }
}
*/
