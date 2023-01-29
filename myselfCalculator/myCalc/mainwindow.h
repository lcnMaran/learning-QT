#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    typedef QPair<float, float> valores;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    valores arguments();

signals:
    void computar(float x);

public slots:
    void about();

    void soma();
    void subtrai();
    void multiplica();
    void divide();

    void showresult(float x);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
