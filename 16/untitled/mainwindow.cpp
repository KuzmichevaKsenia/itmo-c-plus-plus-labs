#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QStringList>
#include <QtMath>

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
    QString str = ui->numberString->text();//введенная пользователем строка

    QStringList list = str.split(" ");//делим строку через пробел

    int capacity = list.size();//создаем массив из введенных вещественных чисел
    double arr[capacity];
    for (int i = 0; i < capacity; ++i) arr[i] = list[i].toDouble();

    int negNumber = 0;//количество отрицательных чисел

    int indexMin = 0;//индекс минимального по модулю элемента

    double sumAbs = 0;//сумма модулей чисел, стоящих после минимального по модулю элемента

    for (int i = 0; i < capacity; ++i) {//считаем negNumber и indexMin
        if (arr[i] < 0) ++negNumber;
        if (qFabs(arr[indexMin]) >= qFabs(arr[i])) indexMin = i;
    }

    for (int i = indexMin + 1; i < capacity; ++i) sumAbs += qFabs(arr[i]); //считаем sumAbs

    str.setNum(negNumber);//выводим ответ в поле negNum
    ui->negNum->setText(str);

    str.setNum(sumAbs);//выводим ответ в поле sum
    ui->sum->setText(str);

    for (int i = 0; i < capacity; ++i)//меняем отрицательные элементы на их квадраты
        if (arr[i] < 0) arr[i] = arr[i] * arr[i];

    double buffer;//буферная переменная

    for (int i = 0; i < capacity - 1; i++) {//сортировка пузырьком по возрастанию
            for (int j = 0; j < capacity - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    buffer = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = buffer;
                }
            }
        }

    str = "";//выводим ответ в поле resultArray
    QString strBuffer = "";
    for (int i = 0; i < capacity; ++i) {
        strBuffer.setNum(arr[i]);
        str.append(strBuffer);
        str.append(" ");
    }
    ui->resultArray->setText(str);
}
