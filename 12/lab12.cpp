#include <iostream>

// линейный двунапрвленный список

struct Node {
    int value; // значение
    Node* prev; // указатель на предыдущий узел
    Node* next; // указатель на следующий узел

    // конструкторы
    Node() : Node(0, 0, 0) {}

    Node(int value) : Node(value, 0, 0) {}

    Node(int value, Node* prev, Node* next) {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

class DoubleList {
    Node* first; // первый узел
    Node* last; // последний узел
    int size; // размерность списка

    void connectNodes(Node* left, Node* right) { // установка связи между соседними узлами
        left->next = right;
        right->prev = left;
    }

    void printNodes(Node* curNode) { // печать всех элементов списка
        if (curNode != last) {
            std::cout << curNode->value << " ";
            printNodes(curNode->next);
        } else {
            std::cout << std::endl;
        }
    }

    Node* getNode(int n) {
        if (n < 1 || n > size) {
            std::cout << "Ошибка: выход за пределы списка" << std::endl;
            return 0;
        }

        Node* result = first;
        while (--n) {
            result = first->next;
        }

        return result;
    }


public:
    DoubleList() { // конструктор
        first = new Node();
        last = new Node();
        size = 0;

        connectNodes(first, last);
    }

    void addToFront(int element) { // добавление элемента в начало
        Node* newNode = new Node(element);

        Node* oldFront = first->next;
        connectNodes(first, newNode);
        connectNodes(newNode, oldFront);
        std::cout << "Добавлен 1-й элемент со значением " << element << std::endl;
        ++size;
    }

    void addToEnd(int element) { // добавление дека в конец
        Node* newNode = new Node(element);

        Node* oldEnd = last->prev;
        connectNodes(oldEnd, newNode);
        connectNodes(newNode, last);
        std::cout << "Добавлен " << size + 1 << "-й элемент со значением " << element << std::endl;
        ++size;
    }

    void insert(int element, int n) { // добавить новый элемент на n-ое место
        if (n < 1 || n > size + 1) {
                std::cout << "Ошибка: выход за пределы списка" << std::endl;
                return;
        }
        if (n == 1) {
            addToFront(element);
        } else
        if (n == size + 1) {
            addToEnd(element);
        } else {
            Node* shiftNode = getNode(n);
            Node* newNode = new Node(element);
            connectNodes(newNode, shiftNode->next);
            connectNodes(shiftNode, newNode);
            std::cout << "Добавлен " << n << "-й элемент со значением " << element << std::endl;
            ++size;
        }
    }

    int popFront() { // удаление и возврат начального элемента
        Node* front = first->next;
        int result = front->value;
        connectNodes(first, front->next);
        delete front;
        std::cout << "Удален 1-й элемент со значением " << result << std::endl;
        --size;
        return result;
    }

    int popEnd() { // удаление и возврат последнего элемента
        Node* end = last->prev;
        int result = end->value;
        connectNodes(end->prev, last);
        delete end;
        std::cout << "Удален " << size << "-й элемент со значением " << result << std::endl;
        --size;
        return result;
    }

    int remove(int n) { // удалить n-й элемент
        if (n < 1 || n > size) {
            std::cout << "Ошибка: выход за пределы списка" << std::endl;
            return 0;
        }

        if (n == 1) {
            return popFront();
        } else
        if (n == size) {
            return popEnd();
        }
        Node* oldNode = getNode(n);
        int result = oldNode->value;
        connectNodes(oldNode->prev, oldNode->next);
        delete oldNode;

        std::cout << "Удален " << n << "-й элемент со значением " << result << std::endl;
        --size;
        return result;
    }

    void printList() {
        std::cout << "Все элементы списка: ";
        printNodes(first->next);
    }

    DeletAll() { // деструктор
        Node* curNode = first->next;
        while(curNode != last) {
            Node* nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
        first = new Node();
        last = new Node();
        size = 0;
        connectNodes(first, last);
        std::cout << "Список очищен" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    DoubleList d; // создаем список d

    d.addToFront(2); // дважды добавляем в начало элементы 2 - 4 и в конец элемент 1
    d.addToFront(3);
    d.addToFront(4);
    d.addToEnd(1);
    d.addToFront(2);
    d.addToFront(3);
    d.addToFront(4);
    d.addToEnd(1);

    d.printList(); // печатаем список

    d.popEnd(); // удаляем 2 элемента с конца
    d.popEnd();
    d.popFront(); // удаляем 2 элемента с начала
    d.popFront();

    d.printList();

    d.DeletAll(); // очищаем список

    d.printList();

    d.insert(5, 1); // добавляем поочередно на превое место элементы 5, 4 и 3
    d.insert(4, 1);
    d.insert(3, 1);
    d.printList();

    d.remove(1); // удаляем 2 раза первый элемент
    d.remove(1);
    d.printList();
    d.DeletAll();
}
