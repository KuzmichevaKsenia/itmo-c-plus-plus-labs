/*
 * Задается структура ZNAK, содержащая переменные firstName,  lastName и sign (знак Зодиака) типа string и
 * целочисленный массив date из 3 элементов для хранения дня, месяца и года рождения соответственно.
 *
 * Функция sort, получает на вход массив типа ZNAK и его размерность, сортирует по дате рождения от старшего возраста
 * к младшему и выводит отсортированный массив.
 *
 * Программе на вход подаются данные о 8 пользователях (в формате: firstName lastName sign date[0] date[1] date[2])
 * и запоминаются в массив array[n] типа ZNAK. Далее вызывается функция sort. Затем программе подается на вход одно
 * слово – знак Зодиака и запоминается в переменную testSign типа string. Если в массиве есть пользователь(и) с таким
 * знаком, то программа выводит всю информацию о нем(них), иначе программа выводит сообщение «No such users».
 * Затем снова требуется ввести знак Зодиака.
 * */

#include <iostream>
#include <iomanip>
using namespace std;

struct ZNAK {
    string firstName;
    string lastName;
    string sign;
    int date[3];// в числовом формате: "день месяц год"
    };

void sort (ZNAK* array, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((array[i].date[2] > array[j].date[2]) or
                ((array[i].date[2] == array[j].date[2]) && (array[i].date[1] > array[j].date[1])) or
                ((array[i].date[2] == array[j].date[2]) && (array[i].date[1] == array[j].date[1]) && (array[i].date[0] > array[j].date[0]))) {
                swap(array[i], array[j]);
                }
        }
    }
    for (int k = 0; k < n; ++k) {
        cout << array[k].firstName << " " << array[k].lastName << " " << array[k].sign << " ";
        for (int p = 0; p < 3; ++p) {
                 cout << setw(4);
                 cout.setf(ios::left);
                 cout << array[k].date[p];
                 }
        cout << endl;
    }
}

int main() {

    const int n = 8;
    ZNAK array[n];

    for (int i = 0; i < n; ++i) {
            cin >> array[i].firstName >> array[i].lastName >> array[i].sign;
            for (int j = 0; j < 3; ++j) cin >> array[i].date[j];
    }
    cout << endl;
    sort (array, n);
    string testSign;
    bool flag; // истина, если есть зарегистрированные под заданным знаком Зодиака

    while(1) {
        cout << endl;
        cin >> testSign;
        cout << endl;
        flag = 0;
        for (int i = 0; i < n; ++i) {
            if (testSign == array[i].sign) {
                    flag = 1;
                    cout << array[i].firstName << " " << array[i].lastName << " " << array[i].sign << " ";
                    for (int j = 0; j < 3; ++j) {
                            cout << setw(4);
                            cout.setf(ios::left);
                            cout << array[i].date[j];
                    }
                    cout << endl;
            }
        }
        if (!flag) {
            cout << "No such users" << endl;
        }
    }
}
