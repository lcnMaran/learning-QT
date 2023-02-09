#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_open, &QPushButton::clicked, this, &MainWindow::openDoc);
    QObject::connect(ui->pushButton_save, &QPushButton::clicked, this, &MainWindow::saveDoc);
    QObject::connect(ui->pushButton_exit, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDoc()
{
    QFile filename = QFileDialog::getOpenFileName(this, "Open .txt", "~/", "QFile files (*.txt)");

    if (!filename.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return;
    }

    while (!filename.atEnd())
    {
        QByteArray line = filename.readAll();
        ui->textEdit->setPlainText(line);
    }
}

void MainWindow::saveDoc()
{
    QFile filename = QFileDialog::getSaveFileName((QWidget* )0, "Save to..", QString(), "*.txt");
        //if (QFileInfo(filename).suffix().isEmpty()) { filename.(".txt"); }

    if(!filename.open(QIODevice::WriteOnly))
    {
        return;
    }
    else
    {
        QTextStream stream(&filename);
        stream << ui->textEdit->toPlainText();
    }

}





