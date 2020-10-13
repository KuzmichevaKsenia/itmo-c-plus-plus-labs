#include <iostream>

// узел очереди
struct Node {
    int value; // хранимое хначение
    Node *next; // указатель на следующий узел

    Node() : Node(0, 0) {} // конструктор для вспомогательных указателей

    Node(int value) : Node(value, 0) {} // конструктор добавлении элемента

    Node(int value, Node *next) {
        this->value = value;
        this->next = next;
    }
};

class Queue {
    Node *head; // указатель на головной узел
    Node *tail; // указатель на хвостовой узел

public:
    Queue() { // при создании новой очереди, головной и хвостовой указатели не на что не указывают
        tail = 0;
        head = 0;
    }

    void enqueue(int element) { // включение нового элемента
        Node *newNode = new Node(element);

        if (tail == 0) {
            tail = newNode;
            head = tail;
        } else {
            head->next = newNode;
            head = newNode;
        }
    }

    int dequeue() { // удаление элемента и возврат его значения
        int result = tail->value;

        Node *oldTail = tail;
        tail = tail->next;
        delete oldTail;

        return result;
    }

    ~Queue() { // деструктор
        Node *curNode = tail;

        while (curNode != 0) {
            Node *nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
    }
};

int main() {
    Queue q; // создали очередь q
    q.enqueue(1); // добавили элементы 1 - 3
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << std::endl; // удалили и вывели 2 элемента
    std::cout << q.dequeue() << std::endl;

    q.enqueue(4); // добавили новый элемент со значением 4

    std::cout << q.dequeue() << std::endl; // удалили и вывели 2 элемента
    std::cout << q.dequeue() << std::endl;

    q.enqueue(5); // добавили новый элемент со значением 5
    std::cout << q.dequeue() << std::endl; // удалили и вывели 1 элемент
}
