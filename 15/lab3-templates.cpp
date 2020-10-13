/*
 * Создать шаблон класса для работы с комплексными числами (Обеспечить выполнение операций сложения, вычитания и
 * умножения комплексных чисел). Написать программу, использующую этот шаблон, задавая вещественную и мнимую части
 * как числами типа double, так и целыми числами.
 * */

#include <iostream>

using namespace std;

template<class Type>
class C {
public:
    Type re; // вещественная часть
    Type im; // мнимая часть
    C(Type x = 0, Type y = 0) {
        re = x;
        im = y;
    } // конструктор

    C(C &c) {
        re = c.re;
        im = c.im;
    } // конструктор копирования

    bool operator==(const C &c) // перегрузка оператора сравнения на равенство
    {
        if ((re == c.re) && (im == c.im))
            return true;
        return false;
    }

    bool operator!=(const C &c) // перегрузка оператора сравнения на неравенство
    {
        if ((re != c.re) || (im != c.im))
            return true;
        return false;
    }

    const C &operator=(const C &c) // перегрузка оператора присваивания
    {
        re = c.re;
        im = c.im;

        return (*this);
    }

    C operator+(C &c) // перегрузка оператора сложения
    {
        C temp;

        temp.re = re + c.re;
        temp.im = im + c.im;

        return temp;
    }

    C operator-(C &c) // перегрузка оператора вычитания
    {
        C temp;

        temp.re = re - c.re;
        temp.im = im - c.im;

        return temp;
    }

    C operator*(C &c) // перегрузка оператора умножения
    {
        C temp;

        temp.re = re * c.re - im * c.im;
        temp.im = re * c.im + im * c.re;

        return temp;
    }

    C sqr() {
        C temp(re, im);
        temp = temp * temp;
        return temp;
    }

    void print() {
        if ((re == 0) && (im == 0)) {
            cout << "0 ";
            return;
        }

        if (re == 0) {
            cout << im << "i ";
            return;
        }

        if (im == 0) {
            cout << re << " ";
            return;
        }

        if (im > 0) cout << re << "+" << im << "i ";
        else cout << re << im << "i ";
    }
};

int main() {
    // для целочисленных значений
    typedef C<int> compInt;
    compInt c1;
    cout << "c1 = ";
    c1.print();

    compInt c2(2, 4);
    cout << endl << "c2 = ";
    c2.print();
    cout << endl;

    if (c1 != c2) {
        c1.print();
        cout << "not equal ";
        c2.print();


        c1 = c1 + c2;
        cout << endl << "c1 = c1 + c2 = ";
        c1.print();
        cout << endl;
    }

    if (c1 == c2) {
        c1.print();
        cout << "equal ";
        c2.print();


        c1 = c1 * c2;
        cout << endl << "c1 = c1 * c2 = ";
        c1.print();
    }

    c1 = c2 - c1;
    cout << endl << "c1 = c2 - c1 = ";
    c1.print();

    c1 = c1.sqr();
    cout << endl << "c1 = sqr(c1) = ";
    c1.print();


    // для значений типа double
    typedef C<double> compDouble;
    compDouble c3;
    cout << endl << endl <<
         "c3 = ";
    c3.print();

    compDouble c4(2.3, 4.1);
    cout << endl << "c4 = ";
    c4.print();
    cout << endl;


    if (c3 != c4) {
        c3.print();
        cout << "not equal ";
        c4.print();


        c3 = c3 + c4;
        cout << endl << "c3 = c3 + c4 = ";
        c3.print();
        cout << endl;
    }

    if (c3 == c4) {
        c3.print();
        cout << "equal ";
        c4.print();


        c3 = c3 * c4;
        cout << endl << "c3 = c3 * c4 = ";
        c3.print();
    }

    c3 = c4 - c3;
    cout << endl << "c3 = c4 - c3 = ";
    c3.print();

    c3 = c3.sqr();
    cout << endl << "c3 = sqr(c3) = ";
    c3.print();

}
