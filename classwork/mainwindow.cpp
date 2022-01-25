#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QString>
#include<vector>
#include<cstring>
#include<cmath>
using namespace  std;
std::vector<std::string> temp;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(drawp==0)                                      //当没有函数图像输入时只画出坐标系图片
    {
        painter.setBrush(QBrush(QColor(255,255,255)));     //设置画刷颜色（白色）
        painter.drawRect(86,100,628,550);                  //画白色填充矩形作为坐标系背景
        painter.setBrush(QBrush(QColor(0,0,0)));           //设置画刷颜色为黑
        painter.drawEllipse(QPoint(400,375),4,4);          //画出原点
        painter.translate(QPoint(400,375));                //设置上述原点位置为绘制原点
        for (int i=-5;i<6;i++)
        {
            if(i!=0)
           {
                QPen pen;
                pen.setWidth(2);
                pen.setColor(Qt::gray);
                pen.setStyle(Qt::DotLine);
                painter.setPen(pen);                                            //设置画笔型号以画出横纵坐标线
                painter.drawLine(-PI*WULENGTH*2,i*HULENGTH,PI*WULENGTH*2,i*HULENGTH);//画横坐标线
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                QString s=QString("%1").arg(i*2*-1);
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                painter.drawText(QPoint(7,i*HULENGTH+5),s);
           }
            else                                                                    //x=0线设置为黑色（其它为灰色）
           {
                QPen pen;
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                painter.drawLine(-PI*WULENGTH*2,i*HULENGTH,PI*WULENGTH*2,i*HULENGTH);
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                QString s=QString("-π"),s1=QString("π");
                painter.drawText(QPoint(-PI*WULENGTH*2-20,15),s);
                painter.drawText(QPoint(PI*WULENGTH*2+5,15),s1);                          //标出相应坐标线所对应的值
           }
        }
        for (int i=-6;i<7;i++)
        {
            if(i!=0)
           {
                QPen pen;
                pen.setWidth(2);
                pen.setColor(Qt::gray);
                pen.setStyle(Qt::DotLine);
                painter.setPen(pen);
                painter.drawLine(i*WULENGTH,-275,i*WULENGTH,275);                    //画纵坐标线
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                int temp;
                if(i%2==0)
                {
                    temp=0;
                }
                else
                {
                    temp=5;
                }
                if(i==-1)
                {
                    QString s=QString("-%1.%2").arg(i/2).arg(temp);
                    painter.drawText(QPoint(i*WULENGTH-12,15),s);                                    //此处为了防止int型变量i=-1时除2等于0负号丢失
                }
                else
                {
                    QString s=QString("%1.%2").arg(i/2).arg(temp);
                    painter.drawText(QPoint(i*WULENGTH-12,15),s);
                }
           }
            else                                                                //y=0线设置为黑色（其它为灰色）
           {
                QPen pen;
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                painter.drawLine(i*WULENGTH,-275,i*WULENGTH,275);
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                QString s=QString("%1").arg(i);
                painter.drawText(QPoint(i*WULENGTH-15,15),s);                    //标出相应坐标线所对应的值
           }
        }

    }
    else                                                   //当有函数图像输入时先画出坐标系图片，然后绘制输入函数图像
    {
        painter.setBrush(QBrush(QColor(255,255,255)));     //设置画刷颜色（白色）
        painter.drawRect(86,100,628,550);                  //画白色填充矩形作为坐标系背景
        painter.setBrush(QBrush(QColor(0,0,0)));           //设置画刷颜色为黑
        painter.drawEllipse(QPoint(400,375),4,4);          //画出原点
        painter.translate(QPoint(400,375));                //设置上述原点位置为绘制原点
        for (int i=-5;i<6;i++)
        {
            if(i!=0)
           {
                QPen pen;
                pen.setWidth(2);
                pen.setColor(Qt::gray);
                pen.setStyle(Qt::DotLine);
                painter.setPen(pen);                                            //设置画笔型号以画出横纵坐标线
                painter.drawLine(-PI*WULENGTH*2,i*HULENGTH,PI*WULENGTH*2,i*HULENGTH);//画横坐标线
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                QString s=QString("%1").arg(i*2*-1);
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                painter.drawText(QPoint(7,i*HULENGTH+5),s);
           }
            else                                                                    //x=0线设置为黑色（其它为灰色）
           {
                QPen pen;
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                painter.drawLine(-PI*WULENGTH*2,i*HULENGTH,PI*WULENGTH*2,i*HULENGTH);
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                QString s=QString("-π"),s1=QString("π");
                painter.drawText(QPoint(-PI*WULENGTH*2-20,15),s);
                painter.drawText(QPoint(PI*WULENGTH*2+5,15),s1);                          //标出相应坐标线所对应的值
           }
        }
        for (int i=-6;i<7;i++)
        {
            if(i!=0)
           {
                QPen pen;
                pen.setWidth(2);
                pen.setColor(Qt::gray);
                pen.setStyle(Qt::DotLine);
                painter.setPen(pen);
                painter.drawLine(i*WULENGTH,-275,i*WULENGTH,275);                    //画纵坐标线
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                int temp;
                if(i%2==0)
                {
                    temp=0;
                }
                else
                {
                    temp=5;
                }
                if(i==-1)
                {
                    QString s=QString("-%1.%2").arg(i/2).arg(temp);
                    painter.drawText(QPoint(i*WULENGTH-12,15),s);                                    //此处为了防止int型变量i=-1时除2等于0负号丢失
                }
                else
                {
                    QString s=QString("%1.%2").arg(i/2).arg(temp);
                    painter.drawText(QPoint(i*WULENGTH-12,15),s);
                }
           }
            else                                                                //y=0线设置为黑色（其它为灰色）
           {
                QPen pen;
                pen.setWidth(3);
                pen.setColor(Qt::black);
                pen.setStyle(Qt::SolidLine);
                painter.setPen(pen);
                painter.drawLine(i*WULENGTH,-275,i*WULENGTH,275);
                QFont font;
                font.setPointSize(8);
                font.setFamily("Microsoft YaHei");
                font.setLetterSpacing(QFont::AbsoluteSpacing,0);
                painter.setFont(font);
                QString s=QString("%1").arg(i);
                painter.drawText(QPoint(i*WULENGTH-15,15),s);                    //标出相应坐标线所对应的值
           }
        }

                                                            //此处以前全为坐标系绘制

        //std::string str1;
        //str1 = string((const char *)str.toLocal8Bit());
          for (int i = 0; i<str.size(); i++)
        {
            if (str[i] == ' ' || str[i] == 'i' || str[i] == 'o' || str[i] == 'n' || (str[i] == 's' && i-1>=0&&(str[i-1] == 'o' || str[i-1] == 'c')))
            {
                str.erase(str.begin()+i);
                i--;
            }
        }

        for(double i=-3.14;i<=3.14;i+=0.001)                             //for循环反复改变x值代入求解式中求出y值
        {
            if (i < 1e-4&&i>-0.001)
            {
                i = 0;
            }
            double a=result(str,i);                                     //求出y值
            int px=i*100.0,py=-a*25;                                    //x，y的值根据窗口单位长度的确定相对原点的位置进行一定的等比缩放
            QPoint temppoint;
            temppoint.setX(px);
            temppoint.setY(py);
            if(abs(py)>275)
            {
                continue;
            }
            painter.drawEllipse(temppoint,2,2);                         //在坐标轴内标出该点（只要点足够密便可呈现出连续的曲线）

        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    str=ui->textEdit->toPlainText().toStdString();//当有文本输入时且绘制按钮被按下把输入文本内容赋值给str变量
    drawp=1;
    repaint();
}
double MainWindow::changetonumber(string a)
{
    double result = 0;
    int dot = 0;
    int change = 0;
    for (int i = 0;a[i]!='\0'; i++)
    {
        if (dot == 0 && a[i] >= '0' && a[i] <= '9')
        {
            result = result * 10 + a[i] - '0';
        }
        else if (a[i]=='.')
        {
            dot = 1;
        }
        else if (dot !=0&& a[i] >= '0' && a[i] <= '9')
        {
            result += double((a[i]-'0'))/pow(10,dot);
            dot++;
        }
        else if(a[i]=='-')
        {
            change = 1;
        }
    }
    if (change == 1)
    {
        result *= -1;
    }
    return result;
}
string MainWindow::changetostring(double a)
{
    string s;
    if (a == 0)
    {
        return "0";
    }
    else if (a < 0)
    {
        s.push_back('-');
        a *= -1;
    }

    vector<int> itemp;
    int b = a;
    a = a - double(b);
    while (b > 0)
    {
        itemp.push_back(b % 10);
        b /= 10;
    }
    for (int i = itemp.size() - 1; i >= 0; i--)
    {
        char ctemp = itemp[i] + '0';
        s.push_back(ctemp);
    }
    s.push_back('.');
    while (b > 0)
    {
        itemp.push_back(b % 10);
        b /= 10;
    }
    int time = 0;
    while (a > 0)
    {
        a *= 10;
        int itemp2 = a;
        char ctemp = itemp2 + '0';
        s.push_back(ctemp);
        a -= double(itemp2);
        if (time == 3)
        {
            break;
        }
        time++;
    }
    return s;
}
void MainWindow::number(int start,int end,int condition,double x)
{
    string result;
    double iresult=0;
    for (int i = start+1; i < end; i++)
    {
        if (temp[i]=="*")
        {
            if (temp[i - 1]!="x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = changetonumber(temp[i-1]) * changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult =  changetonumber(temp[i - 1])*x;
                }
            }
            else if (temp[i - 1] == "x" )
            {
                if (temp[i+1] != "x")
                {
                    iresult = x * changetonumber(temp[i + 1]);
                }
                else if (temp[i +1] == "x")
                {
                    iresult = x * x;
                }
            }
            temp[i - 1] = changetostring(iresult);
            temp.erase(temp.begin() + i +1);
            temp.erase(temp.begin() + i);
            end -= 2;
            i--;
        }
        else if (temp[i] == "/")
        {
            if (temp[i - 1] != "x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = changetonumber(temp[i - 1]) /changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult = changetonumber(temp[i-1])/x;
                }
            }
            else if (temp[i - 1] == "x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = x/ changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult = 1;
                }
            }
            temp[i - 1] = changetostring(iresult);
            temp.erase(temp.begin() + i + 1);
            temp.erase(temp.begin() + i);
            end -= 2;
            i--;
        }
    }
    for (int i = start+1; i < end; i++)
    {
        if (temp[i] == "+")
        {
            if (temp[i - 1] != "x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = changetonumber(temp[i - 1])+changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult = changetonumber(temp[i - 1])+ x ;
                }
            }
            else if (temp[i - 1] == "x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = x + changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult = x+ x;
                }
            }
            temp[i - 1] = changetostring(iresult);
            temp.erase(temp.begin() + i + 1);
            temp.erase(temp.begin() + i);
            end -= 2;
            i--;
        }
        else if (temp[i] == "-")
        {
            if (temp[i - 1] != "x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = changetonumber(temp[i - 1]) - changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult =  changetonumber(temp[i-1])-x;
                }
            }
            else if (temp[i - 1] == "x")
            {
                if (temp[i + 1] != "x")
                {
                    iresult = x - changetonumber(temp[i + 1]);
                }
                else if (temp[i + 1] == "x")
                {
                    iresult =0;
                }
            }
            temp[i - 1] = changetostring(iresult);
            temp.erase(temp.begin() + i + 1);
            temp.erase(temp.begin() + i);
            end -= 2;
            i--;
        }
    }
    if (condition == 1)
    {
        if (temp[start] == "x")
        {
            double tempresult = x;
            temp[start] = changetostring(sin(tempresult));
        }
        else
        {
            double tempresult = changetonumber(temp[start]);
            temp[start] = changetostring(sin(tempresult));
        }
    }
    else if (condition == 2)
    {
        if (temp[start] == "x")
        {
            double tempresult =x;
            temp[start] = changetostring(cos(tempresult));
        }
        else
        {
            double tempresult =changetonumber(temp[start]);
            temp[start] = changetostring(cos(tempresult));
        }
    }
}
double MainWindow::result(string str,double x)
{
    temp.push_back("(");
    string str1;
    for (int i = 0; str[i]!='\0'; i++)
    {

        if ((str[i]>='0'&&str[i]<='9')||str[i]=='.')
        {
            str1.push_back(str[i]);
        }
        else if (str[i] == 'x'|| str[i] == 's'|| str[i] == 'c')
        {
            str1.push_back(str[i]);
        }
        else
        {
            if(str1!="")
            {
                temp.push_back(str1);
            }

            str1 = str[i];
            temp.push_back(str1);
            str1.clear();
        }
    }
    temp.push_back(str1);
    temp.push_back(")");
    int sign = 1;
    while (sign!=0)
    {
        sign = 0;
        for (int i = 1; i < temp.size() - 1; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (temp[j] == "(" && temp[i] != "(" && temp[i] != ")" && temp[i] != "c" && temp[i] != "s")
                {
                    for (int k = i + 1; k < temp.size(); k++)
                    {
                        if (temp[k] == ")")
                        {
                            //处理
                            temp.erase(temp.begin() + k);
                            temp.erase(temp.begin() + j);
                            int condition = 0,n=0;
                            if (j!=0&&temp[j-1] == "s")
                            {
                                condition = 1;
                                temp.erase(temp.begin() + j - 1);
                                n = 1;
                            }
                            else if (j != 0 && temp[j-1] == "c")
                            {
                                condition = 2;
                                temp.erase(temp.begin() + j - 1);
                                n = 1;
                            }
                            number(j-n, k - 2-n, condition, x);
                            j = -1;
                            break;
                        }
                        else if (temp[k] == "(")
                        {
                            break;
                        }
                    }
                }
                if (j == -1)
                {
                    break;
                }
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == "(")
            {
                sign++;
            }
        }
    }
    double myresult=changetonumber(temp[0]);
    temp.clear();
    return myresult;
}
