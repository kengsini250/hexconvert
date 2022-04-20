#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression rx2("[0,1]+");
    QValidator* validator2 = new QRegularExpressionValidator(rx2, this);
    ui->lineEdit2->setValidator(validator2);

    QRegularExpression rx8("[0-7]+");
    QValidator* validator8 = new QRegularExpressionValidator(rx8, this);
    ui->lineEdit8->setValidator(validator8);

    QRegularExpression rx10("[\\d]+");
    QValidator* validator10 = new QRegularExpressionValidator(rx10, this);
    ui->lineEdit10->setValidator(validator10);

    QRegularExpression rx16("[\\da-fA-F]+");
    QValidator* validator16 = new QRegularExpressionValidator(rx16, this);
    ui->lineEdit16->setValidator(validator16);

    connect(ui->lineEdit2,&QLineEdit::textChanged,this,[this](const QString&text){
        bool end;
        flag2 = true;
        if (!flag8 && !flag10 && !flag16) {
            ui->lineEdit8->setText(QString::number(text.toInt(&end, 2),8));
            ui->lineEdit10->setText(QString::number(text.toInt(&end, 2),10));
            ui->lineEdit16->setText(QString::number(text.toInt(&end, 2),16));
        }
        flag2 = false;
    });

    connect(ui->lineEdit8,&QLineEdit::textChanged,this,[this](const QString&text){
        bool end;
        flag8 = true;
        if (!flag2 && !flag10 && !flag16) {
            ui->lineEdit2->setText(QString::number(text.toInt(&end, 8),2));
            ui->lineEdit10->setText(QString::number(text.toInt(&end, 8),10));
            ui->lineEdit16->setText(QString::number(text.toInt(&end, 8),16));
        }
        flag8 = false;
    });

    connect(ui->lineEdit10,&QLineEdit::textChanged,this,[this](const QString&text){
        bool end;
        flag10 = true;
        if (!flag2 && !flag8 && !flag16) {
            ui->lineEdit2->setText(QString::number(text.toInt(&end, 10),2));
            ui->lineEdit8->setText(QString::number(text.toInt(&end, 10),8));
            ui->lineEdit16->setText(QString::number(text.toInt(&end, 10),16));
        }
        flag10 = false;
    });

    connect(ui->lineEdit16,&QLineEdit::textChanged,this,[this](const QString&text){
        bool end;
        flag16 = true;
        if (!flag2 && !flag10 && !flag8) {
            ui->lineEdit8->setText(QString::number(text.toInt(&end, 16),8));
            ui->lineEdit10->setText(QString::number(text.toInt(&end, 16),10));
            ui->lineEdit2->setText(QString::number(text.toInt(&end, 16),2));
        }
        flag16 = false;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

