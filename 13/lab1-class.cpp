/*
 * Составить описание класса одномерных массивов строк, каждая строка задается длиной и указателем на выделенную для
 * нее память. Предусмотреть контроль выхода за пределы массивов, возможность обращения к отдельным строкам массива по
 * индексам, выполнения операций поэлементного сцепления двух массивов с образованием нового массива, слияния двух
 * массивов с исключением повторяющихся элементов, а также вывод на экран элемента массива и всего массива.
 *
 * Написать программу, демонстрирующую работу с этим классом. Программа должна содержать меню, позволяющее осуществить
 * проверку всех методов класса
 * */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class StringArray {
    static const int INITIAL_CAPACITY = 1;
    int capacity;
    int size;
    string *elements;

    void ensureCapacity();

    void append(const string &str);

    const bool contains(const string &element);

public:

    StringArray(int capacity = INITIAL_CAPACITY) {
        size = 0;
        this->capacity = capacity;
        elements = new string[capacity];
    }

    ~StringArray() {
        delete[] elements;
    }

    void append(StringArray &other);

    void recreate();

    void print();

    void printString();

    void join(StringArray &other);

    const int getSize();

    string &operator[](int i) {
        return elements[i];
    }

    const string &operator[](int i) const {
        return elements[i];
    }
};

char test[1];

int main() {
    StringArray array1, array2;
    cout << "1 - create first array" << endl;
    cout << "2 - create second array" << endl;
    cout << "3 - print first array" << endl;
    cout << "4 - print second array" << endl;
    cout << "5 - print string of first array by index" << endl;
    cout << "6 - print string of second array by index" << endl;
    cout << "7 - join arrays" << endl;
    cout << "8 - append arrays" << endl;
    cout << "9 - exit" << endl;
    do {
        cout << endl << "Enter a menu item -> ";
        cin >> test;
        switch (atoi(test)) {
            case 1:
                array1.recreate();
                continue;
            case 2:
                array2.recreate();
                continue;
            case 3:
                array1.print();
                continue;
            case 4:
                array2.print();
                continue;
            case 5:
                array1.printString();
                continue;
            case 6:
                array2.printString();
                continue;
            case 7:
                array1.join(array2);
                continue;
            case 8:
                array1.append(array2);
                continue;
            case 9:
                return 0;
            default:
                cout << "WRONG KEY! TRY AGAIN!" << endl;
                continue;
        }
    } while (1);
}

void StringArray::ensureCapacity() {
    capacity *= 2;
    string *newElements = new string[capacity];
    for (int i = 0; i < size; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

void StringArray::append(const string &str) {
    if (size >= capacity) {
        ensureCapacity();
    }
    elements[size++] = str;
}

const int StringArray::getSize() {
    return size;
}

const bool StringArray::contains(const string &element) {
    for (int i = 0; i < getSize(); ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

void StringArray::append(StringArray &other) {
    for (int i = 0; i < other.getSize(); ++i) {
        if (!contains(other[i])) {
            append(other[i]);
        }
    }
}

void StringArray::recreate() {
    delete[] elements;
    cout << "Enter number of strings -> ";
    cin >> test;
    int n = atoi(test);
    if (n > 0) {
        elements = new string[atoi(test)];
        cin.ignore();
        string str;
        for (int i = 0; i < atoi(test); ++i) {
            cout << "Enter " << i + 1 << " string -> ";
            getline(cin, str);
            append(str);
        }
    } else cout << "WRONG NUMBER!" << endl;
}

void StringArray::print() {
    for (int i = 0; i < getSize(); ++i) {
        cout << elements[i] << endl;
    }
}

void StringArray::printString() {
    cout << "Enter string index -> ";
    cin >> test;
    int index = atoi(test);
    if (index > 0 && index <= size) {
        cout << elements[--index] << endl;
    } else cout << "WRONG INDEX!" << endl;
}

void StringArray::join(StringArray &other) {
    for (int i = 0; i < other.getSize(); ++i) {
        append(other[i]);
    }
}
