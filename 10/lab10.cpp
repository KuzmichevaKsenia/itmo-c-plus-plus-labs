#include <iostream>

// узел дека
struct Node {
    int value; // значение
    Node *prev; // указатель на предыдущий узел
    Node *next; // указатель на следующий узел

    // конструкторы
    Node() : Node(0, 0, 0) {}

    Node(int value) : Node(value, 0, 0) {}

    Node(int value, Node *prev, Node *next) {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

class Dequeue {
    Node *first; // первый узел
    Node *last; // последний узел

    void connectNodes(Node *left, Node *right) { // установка связи между соседними узлами
        left->next = right;
        right->prev = left;
    }

public:
    Dequeue() { // конструктор дека
        first = new Node();
        last = new Node();

        connectNodes(first, last);
    }

    void addToFront(int element) { // добавление элемента в начало
        Node *newNode = new Node(element);

        Node *oldFront = first->next;
        connectNodes(first, newNode);
        connectNodes(newNode, oldFront);
    }

    void addToEnd(int element) { // добавление дека в конец
        Node *newNode = new Node(element);

        Node *oldEnd = last->prev;
        connectNodes(oldEnd, newNode);
        connectNodes(newNode, last);
    }

    int popFront() { // удаление и возврат начального элемента
        Node *front = first->next;
        int result = front->value;
        connectNodes(first, front->next);
        delete front;
        return result;
    }

    int popEnd() { // удаление и возврат последнего элемента
        Node *end = last->prev;
        int result = end->value;
        connectNodes(end->prev, last);
        delete end;
        return result;
    }

    ~Dequeue() { // деструктор
        Node *curNode = first->next;

        while (curNode != last) {
            Node *nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
            std::cout << "Delete ";
        }
    }
};

int main() {
    Dequeue d; // создаем дек d

    d.addToFront(2); // добавляем в начало элементы 2 - 4
    d.addToFront(3);
    d.addToFront(4);

    d.addToEnd(1); // добавляем в конец элемент 1

    d.addToFront(2); // добавляем в начало элементы 2 - 4
    d.addToFront(3);
    d.addToFront(4);

    d.addToEnd(1); // добавляем в конец элемент 1

    std::cout << d.popEnd() << std::endl; // удаляем и выводим 2 элемента с конца
    std::cout << d.popEnd() << std::endl;
    std::cout << d.popFront() << std::endl; // удаляем и выводим 2 элемента из начала
    std::cout << d.popFront() << std::endl;
}
