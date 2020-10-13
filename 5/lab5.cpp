/*
 * Программа задает 2 массива: X[len] и Y[len] для хранения x- и y- координат 18-ти точек, заполняет его случайными
 * положительными числами до 100 и печатает полученные точки. Затем циклом программа находит различные 3 точки для
 * первого треугольника abc (с координатами (X[a], Y[a]), (X[b], Y[b]), (X[c], Y[c])); далее программа ищет
 * 3 точки a1, b1 и c1 (отличных от a, b , c) для второго треугольника, проверяя вложенность этого треугольника
 * в первый; и 3 точки a2, b2 и c2 (отличных от уже взятых), также проверяя условие вложенности третьего треугольника
 * во второй. Как только найдется 3 вложенных друг в друга треугольника, программа выводит координаты их вершин
 * на экран и цикл завершается. Если такие треугольники не найдены, выводится сообщение об этом.
 *
 * Функция логического типа pointOnRightSide на вход получает координаты 4-х точек. Через (x1, y1) и (x2, y2)
 * задается уравнение прямой. Далее проверяется условие: лежат ли точки (x3, y3) и (x4, y4) по одну сторону от этой
 * прямой. Функция возвращает результат проверки этого условия.
 *
 * Функция логического типа pointInTr на вход получает координаты 4-х точек, где первые 3 точки – вершины треугольника,
 * а 4-я точка проверяется функцией на вложенность в данный треугольник. Если pointOnRightSide для каждой стороны
 * треугольника true, то функция возвращает true, иначе точка не в треугольнике => false.
 * */

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

bool pointOnRightSide(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double res1 = (y1 - y2) * (x3 - x2) / (x1 - x2) + y2 - y3;
    double res2 = (y1 - y2) * (x4 - x2) / (x1 - x2) + y2 - y4;
    if ((res1 >= 0) && (res2 >= 0) || (res1 < 0) && (res2 < 0))
        return true;
    else return false;
}

bool pointInTr(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    if (pointOnRightSide(x1, y1, x2, y2, x3, y3, x4, y4) && pointOnRightSide(x1, y1, x3, y3, x2, y2, x4, y4) &&
        pointOnRightSide(x2, y2, x3, y3, x1, y1, x4, y4))
        return true;
    else return false;
}

int main() {

    const int len = 18;
    double X[len];
    double Y[len];

    cout << "The origin coordinates of points: ";
    srand(time(0));
    for (int i = 0; i < len; ++i) {
        X[i] = rand() % 100;
        Y[i] = rand() % 100;
        cout << "(" << X[i] << ", " << Y[i] << ") ";
    }
    cout << endl << endl;

    for (int a = 0; a < len - 2; ++a) {
        for (int b = 1; b < len - 1; ++b) {
            if (a != b)
                for (int c = 2; c < len; ++c) {
                    if ((b != c) && (a != c))
                        for (int a1 = 0; a1 < len - 2; ++a1) {
                            if ((a1 != a) && (a1 != b) && (a1 != c) &&
                                pointInTr(X[a], Y[a], X[b], Y[b], X[c], Y[c], X[a1], Y[a1]))
                                for (int b1 = 1; b1 < len - 1; ++b1) {
                                    if ((b1 != a1) && (b1 != a) && (b1 != b) && (b1 != c) &&
                                        pointInTr(X[a], Y[a], X[b], Y[b], X[c], Y[c], X[b1], Y[b1]))
                                        for (int c1 = 2; c1 < len; ++c1) {
                                            if ((c1 != b1) && (c1 != a1) && (c1 != a) && (c1 != b) && (c1 != c) &&
                                                pointInTr(X[a], Y[a], X[b], Y[b], X[c], Y[c], X[c1], Y[c1]))
                                                for (int a2 = 0; a2 < len - 2; ++a2) {
                                                    if ((a2 != c1) && (a2 != b1) && (a2 != a1) && (a2 != a) &&
                                                        (a2 != b) && (a2 != c) &&
                                                        pointInTr(X[a1], Y[a1], X[b1], Y[b1], X[c1], Y[c1], X[a2],
                                                                  Y[a2]))
                                                        for (int b2 = 1; b2 < len - 1; ++b2) {
                                                            if ((b2 != a2) && (b2 != c1) && (b2 != b1) && (b2 != a1) &&
                                                                (b2 != a) && (b2 != b) && (b2 != c) &&
                                                                pointInTr(X[a1], Y[a1], X[b1], Y[b1], X[c1], Y[c1],
                                                                          X[b2], Y[b2]))
                                                                for (int c2 = 2; c2 < len; ++c2) {
                                                                    if ((c2 != b2) && (c2 != a2) && (c2 != c1) &&
                                                                        (c2 != b1) && (c2 != a1) && (c2 != a) &&
                                                                        (c2 != b) && (c2 != c) &&
                                                                        pointInTr(X[a1], Y[a1], X[b1], Y[b1], X[c1],
                                                                                  Y[c1], X[c2], Y[c2])) {

                                                                        cout
                                                                                << "Coordinates of points of the first triangle: "
                                                                                << "(" << X[a] << ", " << Y[a] << "), "
                                                                                << "(" << X[b] << ", " << Y[b] << "), "
                                                                                << "(" << X[c] << ", " << Y[c] << ")"
                                                                                << endl;
                                                                        cout
                                                                                << "Coordinates of points of the second triangle: "
                                                                                << "(" << X[a1] << ", " << Y[a1]
                                                                                << "), " << "(" << X[b1] << ", "
                                                                                << Y[b1] << "), " << "(" << X[c1]
                                                                                << ", " << Y[c1] << ")" << endl;
                                                                        cout
                                                                                << "Coordinates of points of the third triangle: "
                                                                                << "(" << X[a2] << ", " << Y[a2]
                                                                                << "), " << "(" << X[b2] << ", "
                                                                                << Y[b2] << "), " << "(" << X[c2]
                                                                                << ", " << Y[c2] << ")" << endl;
                                                                        goto finish;
                                                                    }

                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
    }
    cout << "3 nested triangles not found";
    finish:;
}
