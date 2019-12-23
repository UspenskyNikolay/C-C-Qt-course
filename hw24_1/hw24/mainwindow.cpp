#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Рисуем график y=x*x

        //Сгенерируем данные
        //Для этого создадим два массива точек:
        //один для сохранения x координат точек,
        //а второй для y соответственно

        double a = -1;          //Начало интервала, где рисуем график по оси Ox
        double b =  1;          //Конец интервала, где рисуем график по оси Ox
        double h = 0.01;        //Шаг, с которым будем пробегать по оси Ox

        int N=(b-a)/h + 2;          //Вычисляем количество точек, которые будем отрисовывать
        QVector<double> x(N), y(N); //Массивы координат точек


         //Вычисляем наши данные
       // int i=0;
    /*  for (double X=a; X<=b; X+=h)        //Пробегаем по всем точкам
        {
            x[i] = X;
            y[i] = X*X;                     //Формула нашей функции
            i++;
        }*/

         //Запись векторов значений в файл
        QFile file("file.txt");
  /*      if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        {
            qDebug() << "Ошибка при открытии файла";
        }
            QTextStream out(&file);
            for(int i=0; i< x.size(); i++) // запись
            out << x[i]  << "\t" << y[i]  << endl;
            file.close(); */

        //Чтение значений из файла в вектора

             if(file.open(QIODevice::ReadOnly |QIODevice::Text))
                {
                    while(!file.atEnd())
                    {
                        QString str = file.readLine();          //читаем строку
                        QStringList lst = str.split("\t");      //Делим строку на слова разделенные табуляцией
                         QString str1, str2;
                         str1 = lst.at(0);
                         str2 = lst.at(1);
                        //qDebug() << str1.toDouble() << str2.toDouble();    //выводим первые два слова

                        for (int i=0; i< x.size(); i++)
                        {
                            x[i] = str1.toDouble();
                            y[i] = str2.toDouble();
                         }
                        //qDebug() << x[i] << y[i];
                    }
                }
                else
                {
                    qDebug()<< "Файл не открыт!";
                }

             for (int i=0; i< x.size(); i++)
              qDebug() << x[i] << y[i];

        ui->widget->clearGraphs();//Если нужно, то очищаем все графики
        //Добавляем один график в widget
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y);

        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(a, b);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double minY = y[0], maxY = y[0];
        for (int i=1; i<N; i++)
        {
            if (y[i]<minY) minY = y[i];
            if (y[i]>maxY) maxY = y[i];
        }
        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

        //И перерисуем график на нашем widget
        ui->widget->replot();
}
