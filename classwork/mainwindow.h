#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define PI 3.14
#define WULENGTH 50
#define HULENGTH 50
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
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
   double changetonumber(std::string a);
   std::string changetostring(double a);
   void number(int start,int end,int condition,double x);
   double result(std::string str,double x);
private:
    Ui::MainWindow *ui;

    std::string str="";
    int drawp=0;
    std::vector<QPoint> allpoint;
};
#endif // MAINWINDOW_H
