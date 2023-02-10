#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "QMessageBox"
#include "QByteArray"
#include "QFileDialog"
#include "QStandardPaths"
#include <QTextStream>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openDoc();
    void saveDoc();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
