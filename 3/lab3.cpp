#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n; //размер массива
    cout << "Введите размер массива: ";
    cin >> n; // получение от пользователя размера массива
    float *mass = new float[n]; // Выделение памяти для массива
    for (int i = 0; i < n; i++) {
        // Заполнение массива и вывод значений его элементов
        cout << i << "-й элемент массива = ";
        cin >> mass[i];
    }
    cout << endl;
    int k = 0;
    int minm = 0;
    for (int i = 0; i < n; i++) {
        if (mass[i] < 0) k++; //ЛИНЕЙНЫЙ ПОИСК количества отрицательных элементов массива
        if (abs(mass[minm]) > abs(mass[i]))
            minm = i; //Линейный поиск индекса элемента с минимальным по модулю значением
    }
    cout << "В массиве " << k << " отрицательных элементов" << endl;
    cout << endl;

    float sum = 0;
    for (int i = minm + 1; i < n; i++) {
        sum = sum + abs(mass[i]);
    }
    cout << "Сумма модулей элементов массива, расположенных после минимального по модулю элемента равна " << sum
         << endl;
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (mass[i] < 0) mass[i] = pow(mass[i], 2);
    }

    int x; // переменная для обмена элементов местами

    // СОРТИРОВКА МАССИВА ПУЗЫРЬКОМ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {
                // меняем элементы местами
                x = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = x;
            }
        }
    }

    cout << "Все отрицательные элементы массива заменены их квадратами. Массив отсортирован по возрастанию." << endl;
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    delete[] mass; // освобождение памяти;

    return 0;
}
