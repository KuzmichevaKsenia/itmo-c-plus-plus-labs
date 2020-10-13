/*
 * Программа создает массив matrix[rows][cols] размером 6*5, заполняет его случайными целыми числами от -1 до 4
 * включительно и выводит данную матрицу. Затем программа находит максимальное количество одинаковых элементов  в
 * первой второй строках, меняет местами строки, если они не упорядочены по возрастанию количества одинаковых
 * элементов, повторяя этот цикл до конца массива. Вывод отсортированного массива.
 *
 * Для нахождения первого столбца, не содержащего отрицательные элементы: вводим флаг allNotNeg ; циклом проходим по
 * массиву:  allNotNeg принимаем за истину, если в столбце встречается отрицательный элемент, переходим к следующему
 * столбцу, обнуляя флаг. Как только после перебора элементов столбца флаг останется true, выходим из всего цикла и
 * печатаем номер столбца.
 *
 * Функция maxEqualCnt возвращает максимальное количество одинаковых элементов заданного одномерного массива.
 * Функция compareRows  сранивает maxEqualCnt для двух сток массива. Если для первой строки maxEqualCnt больше, чем
 * для второй, функция возвращает положительное значение, в противном случае, отрицательное.
 * */

#include <iostream>
#include <ctime>
#include <stdlib.h>

int maxEqualCnt(int a[], int len) {
    int res = 0;

    for (int i = 0; i < len; ++i) {
        int cnt = 0;

        for (int j = 0; j < len; ++j) {
            if (a[i] == a[j]) {
                cnt++;
            }
        }

        if (cnt > res) {
            res = cnt;
        }
    }

    return res;
}

int compareRows(int a1[], int len1, int a2[], int len2) {
    int maxEqualCnt1 = maxEqualCnt(a1, len1);
    int maxEqualCnt2 = maxEqualCnt(a2, len2);

    return maxEqualCnt1 - maxEqualCnt2;
}


int main() {
    const int rows = 6, cols = 5;
    int matrix[rows][cols];

    srand(time(NULL));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 6 - 1;
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows - 1; ++j) {
            if (compareRows(matrix[j], cols, matrix[j + 1], cols) > 0) {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < cols; ++i) {
        bool allNotNeg = true;

        for (int j = 0; j < rows; ++j) {
            if (matrix[j][i] < 0) {
                allNotNeg = false;
                break;
            }
        }

        if (allNotNeg) {
            std::cout << i << std::endl;
            break;
        }
    }

}

