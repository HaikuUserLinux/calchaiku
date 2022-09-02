#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("/");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double a, b;
    double res;
    a = ui->textEdit->toPlainText().toDouble();
    b = ui->textEdit_2->toPlainText().toDouble();
    int act = ui->comboBox->currentIndex();
    switch(act)
    {
        case 0:
        {
            res = a + b;
            ui->textEdit_3->setText(QString::number(res));
            break;
        }
        case 1:
        {
            res = a - b;
            ui->textEdit_3->setText(QString::number(res));
            break;
        }
        case 2:
        {
            res = a * b;
            ui->textEdit_3->setText(QString::number(res));
            break;
        }
        case 3:
        {
            if (b == 0)
            {
                ui->textEdit_3->setText("Cannot divide by zero!");
            }
            else
            {
                res = a / b;
                ui->textEdit_3->setText(QString::number(res));
            }
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_3->setText("");
}

