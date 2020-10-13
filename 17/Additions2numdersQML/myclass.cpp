#include "myclass.h"
#include <QStringList>
#include <QtMath>

void MyClass::buttonClicked()
{
    //Найдем строку ввода
    QObject* textinput = viewer->findChild<QObject*>("textinput");
    //Найдем поля вывода
    QObject* memo1 = viewer->findChild<QObject*>("memo1");
    QObject* memo2 = viewer->findChild<QObject*>("memo2");
    QObject* memo3 = viewer->findChild<QObject*>("memo3");

    //Считаем информацию со строки ввода через свойство text
    QString str=(textinput->property("text")).toString();

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

        QString strResult=QString::number(negNumber);//Переведем результат в строку

        //выведем в поле вывода нашу информацию
        memo1->setProperty("text", strResult);

        strResult=QString::number(sumAbs);
        memo2->setProperty("text", strResult);

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

        strResult = "";//выводим ответ в поле resultArray
        QString strBuffer = "";
        for (int i = 0; i < capacity; ++i) {
            strBuffer=QString::number(arr[i]);
            strResult.append(strBuffer);
            strResult.append(" ");
        }
        memo3->setProperty("text", strResult);
}
