#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_about, &QPushButton::clicked, this, &MainWindow::about);
    QObject::connect(ui->actionExit, &QAction::triggered, this , &MainWindow::close);

    QObject::connect(this, &MainWindow::computar, this, &MainWindow::showresult);
    QObject::connect(ui->pushButton_soma,   &QPushButton::clicked, this, &MainWindow::soma);
    QObject::connect(ui->pushButton_menos,  &QPushButton::clicked, this, &MainWindow::subtrai);
    QObject::connect(ui->pushButton_mult,   &QPushButton::clicked, this, &MainWindow::multiplica);
    QObject::connect(ui->pushButton_divide, &QPushButton::clicked, this, &MainWindow::divide);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
{
    QMessageBox msgAbout;
    msgAbout.setText("Hello World.\nMy first aplication!");
    msgAbout.setWindowTitle("About me");
    msgAbout.exec();
}

MainWindow::valores MainWindow::arguments()
{
    bool ok_a, ok_b;
    float a = ui->lineEdit_1->text().toFloat(&ok_a);
    float b = ui->lineEdit_2->text().toFloat(&ok_b);

    if(!ok_a || !ok_b)
    {
        QMessageBox msgAbout;
        msgAbout.setText("Valores de entrada incorretos");
        msgAbout.setWindowTitle("ERRO");
        msgAbout.exec();
    }
    return valores(a,b);
}

void MainWindow::showresult(float x)
{
    ui->label_total->setText(QString::number(x));
}

void MainWindow::soma()
{
    valores y = arguments();
    emit computar(y.first + y.second);
}

void MainWindow::subtrai()
{
    valores y = arguments();
    emit computar(y.first - y.second);
}

void MainWindow::multiplica()
{
    valores y = arguments();
    emit computar(y.first * y.second);
}

void MainWindow::divide()
{
    valores y = arguments();
    emit computar(y.first / y.second);
}
