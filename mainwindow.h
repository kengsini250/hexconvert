#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QValidator>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString temp;

    QTimer* timer2,*timer8,*timer10,*timer16;
    bool flag2 = false;
    bool flag8 = false;
    bool flag10 = false;
    bool flag16 = false;
};
#endif // MAINWINDOW_H
