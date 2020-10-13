#include <iostream>

using namespace std;

const int CAPACITY = 10;

// стек на массиве
class ArrayStack {
// Приватные поля и методы( недоступные за пределами структуры)
    // емкость стека
    int capacity;
    // элементы, хранящиеся в стеке
    int *elems;
    // номер позиции в массиве, куда нужно добавлять следующий элемент
    int pos;

    // проверяем, осталось ли место в массиве. Если нет - увеличиваем массив в 2 раза
    void ensureCapacity() {
        if (pos < capacity) {
            return;
        }

        int *newElems = new int[capacity * 2];

        for (int i = 0; i < capacity; ++i) {
            newElems[i] = elems[i];
        }

        delete[] elems;

        elems = newElems;
        capacity *= 2;
    }

public:

    //конструктор с параметром
    ArrayStack(int capacity) {
        pos = 0;
        this->capacity = capacity;
        elems = new int[capacity];
    }

    //конструктор по умолчанию
    ArrayStack() : ArrayStack(CAPACITY) {}

    // добавить эелемент в стек
    void push(int elem) {
        ensureCapacity();
        elems[pos++] = elem;
    }

    // вывести и удалить элемент из стека
    int pop() {
        return elems[--pos];
    }

    // деструктор - освобождаем память
    ~ArrayStack() {
        delete[] elems;
    }

    // вывод стека
    void printStack() {
        for (int i = 0; i < pos; ++i) {
            cout << elems[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayStack myArrayStack = ArrayStack(); // создали стек на массиве myArrayStack

    myArrayStack.push(1); // добавляем в myArrayStack элементы из чисел 1 - 4
    myArrayStack.push(2);
    myArrayStack.push(3);
    myArrayStack.push(4);
    myArrayStack.printStack();  // выводим стек
    cout << myArrayStack.pop() << endl;  // выводим элемент из myArrayStack и удаляем этот элемент
    myArrayStack.push(17);
    myArrayStack.printStack();  // выводим стек

}
