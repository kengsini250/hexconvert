#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define SLEEP_TIME 1000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [this] {ui->textEdit->clear(); });

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


    timer2 = new QTimer(this);
    timer8 = new QTimer(this);
    timer10 = new QTimer(this);
    timer16 = new QTimer(this);

    connect(timer2, &QTimer::timeout, this, [this] {
        QString text = temp;
        timer2->stop();
        bool end;
        flag2 = true;
        if (!flag8 && !flag10 && !flag16) {
            QString t8 = QString::number(text.toInt(&end, 2), 8);
            QString t10 = QString::number(text.toInt(&end, 2), 10);
            QString t16 = QString::number(text.toInt(&end, 2), 16);

            ui->lineEdit8->setText(t8);
            ui->lineEdit10->setText(t10);
            ui->lineEdit16->setText(t16);

            ui->textEdit->append(text + "     " + t8 + "     " + t10 + "     " + t16);
        }
        flag2 = false;
        });
    connect(ui->lineEdit2, &QLineEdit::textChanged, this, [this](const QString& text) {
        if (!flag8 && !flag10 && !flag16) {
            temp = text;
            timer2->stop();
            timer2->start(SLEEP_TIME);
        }
        });

    connect(timer8, &QTimer::timeout, this, [this] {
        QString text = temp;
        timer8->stop();
        bool end;
        flag8 = true;
        if (!flag2 && !flag10 && !flag16) {
            QString t2 = QString::number(text.toInt(&end, 8), 2);
            QString t10 = QString::number(text.toInt(&end, 8), 10);
            QString t16 = QString::number(text.toInt(&end, 8), 16);

            ui->lineEdit2->setText(t2);
            ui->lineEdit10->setText(t10);
            ui->lineEdit16->setText(t16);

            ui->textEdit->append(text + "     " + t2 + "     " + t10 + "     " + t16);
        }
        flag8 = false;
        });
    connect(ui->lineEdit8, &QLineEdit::textChanged, this, [this](const QString& text) {
        if (!flag2 && !flag10 && !flag16) {
            temp = text;
            timer8->stop();
            timer8->start(SLEEP_TIME);
        }
        });


    connect(timer10, &QTimer::timeout, this, [this] {
        QString text = temp;
        timer10->stop();
        bool end;
        flag10 = true;
        if (!flag2 && !flag8 && !flag16) {
            QString t2 = QString::number(text.toInt(&end, 10), 2);
            QString t8 = QString::number(text.toInt(&end, 10), 8);
            QString t16 = QString::number(text.toInt(&end, 10), 16);

            ui->lineEdit2->setText(t2);
            ui->lineEdit8->setText(t8);
            ui->lineEdit16->setText(t16);

            ui->textEdit->append(text + "     " + t2 + "     " + t8 + "     " + t16);
        }
        flag10 = false;
        });
    connect(ui->lineEdit10, &QLineEdit::textChanged, this, [this](const QString& text) {
        if (!flag2 && !flag8 && !flag16) {
            temp = text;
            timer10->stop();
            timer10->start(SLEEP_TIME);
        }
        });

    connect(timer16, &QTimer::timeout, this, [this] {
        QString text = temp;
        timer16->stop();
        bool end;
        flag16 = true;
        if (!flag2 && !flag8 && !flag10) {
            QString t2 = QString::number(text.toInt(&end, 16), 2);
            QString t8 = QString::number(text.toInt(&end, 16), 8);
            QString t10 = QString::number(text.toInt(&end, 16), 10);

            ui->lineEdit2->setText(t2);
            ui->lineEdit8->setText(t8);
            ui->lineEdit10->setText(t10);

            ui->textEdit->append(text + "     " + t2 + "     " + t8 + "     " + t10);
        }
        flag16 = false;
        });
    connect(ui->lineEdit16, &QLineEdit::textChanged, this, [this](const QString& text) {
        if (!flag2 && !flag8 && !flag10) {
            temp = text;
            timer16->stop();
            timer16->start(SLEEP_TIME);
        }
        });


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer10;
    delete timer16;
    delete timer8;
    delete timer2;
}

