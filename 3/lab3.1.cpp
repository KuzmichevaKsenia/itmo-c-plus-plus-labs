/*
 * Сравнение методов сортировки: Пузырек, Выбор, Шелл. Сравнение поисков: линейного  и двоичного.
 *
Пузырек	3сек
Выбор	3сек
Шелл	4сек
Линейный поиск	3сек
Двоичный поиск	2сек
 * */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <locale>

using namespace std;

void bubble(int n, int a[]) {
    unsigned int start_time = clock();
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время сортировки массива по возрастанию методом пузырька: " << search_time << "сек" << endl;
}

void choice(int n, int a[]) {
    unsigned int start_time = clock();
    for (int i = 0; i < n; i++) {
        int minm = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minm]) { minm = j; }
        }
        swap(a[i], a[minm]);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время сортировки массива по возрастанию методом выбора: " << search_time << "сек" << endl;
}

void shell(int n, int a[]) {
    unsigned int start_time = clock();
    int step = n / 2;
    while (step > 0) {
        for (int i = 0; i < (n - step); i++) {
            int j = i;
            while (j >= 0 && a[j] > a[j + step]) {
                int temp = a[j];
                a[j] = a[j + step];
                a[j + step] = temp;
                j--;
            }
        }
        step = step / 2;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время сортировки массива по возрастанию методом Шелла: " << search_time << "сек" << endl;
}

void linsearch(int n, int a[]) {
    unsigned int start_time = clock();
    int index = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0)
            index = i;
    }
    if (index >= 0)
        cout << index << endl;
    else cout << "нет элементов, равных нулю" << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время линейного поиска индекса элемента массива со значением 0: " << search_time << "сек" << endl;
}

void binsearch(int n, int a[], int left, int right) {
    unsigned int start_time = clock();
    int index = -1;
    int step = n / 2;
    while (step > 0) {
        for (int i = 0; i < (n - step); i++) {
            int j = i;
            while (j >= 0 && a[j] > a[j + step]) {
                int temp = a[j];
                a[j] = a[j + step];
                a[j + step] = temp;
                j--;
            }
        }
        step = step / 2;
    }
    int midd = 0;
    while (left <= right) {
        midd = right / 2;
        if (0 < a[midd])
            right = midd - 1;
        else if (0 > a[midd])
            left = midd + 1;
        else
            index = midd;
    }
    if (index >= 0)
        cout << index << endl;
    else cout << "нет элементов, равных нулю" << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время бинарного поиска индекса элемента массива со значением 0: " << search_time << "сек" << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    //ofstream cout ("output3.1.txt");
    int n = 30000;
    int a[n];
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
    }
    cout << "Начальный массив" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    bubble(n, a);
    cout << endl;
    cout << endl;
    choice(n, a);
    cout << endl;
    cout << endl;
    shell(n, a);
    cout << endl;
    cout << endl;
    linsearch(n, a);
    cout << endl;
    cout << endl;
    binsearch(n, a, 0, n);

    return 0;
}
