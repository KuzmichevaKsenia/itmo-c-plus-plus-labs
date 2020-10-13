#include <iostream>

using namespace std;

// стек на списке
struct Node {
    int element; // элемент стека
    Node *next; // указатель на следующий узел

    // конструктор узла
    Node(int element, Node *next) {
        this->element = element;
        this->next = next;
    }
};

class LinkedStack {
// Приватные поля и методы( недоступные за пределами структуры)

    Node *head; // указатель на головной узел

    void printNodes(Node *curNode) { //вывода стека
        if (curNode != 0) {
            cout << curNode->element << " ";
            printNodes(curNode->next);
        } else {
            cout << endl;
        }
    }

public:
    LinkedStack() {
        head = 0;
    }

    // добавить эелемент в стек
    void push(int elem) {
        Node *newHead = new Node(elem, head);
        head = newHead;
    }

    // вывести и удалить элемент из стека
    int pop() {
        int result = head->element;
        Node *oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }

    // вывод стека
    void printStack() {
        printNodes(head);
    }

    // деструктор - освобождаем память
    ~LinkedStack() {
        Node *curNode = head;

        while (curNode != 0) {
            Node *nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
    }
};

int main() {
    LinkedStack myLinkedStack = LinkedStack();   // создали стек на списке myLinkedStack

    myLinkedStack.push(5);   // добавляем в myLinkedStack элементы из чисел 5 - 8
    myLinkedStack.push(6);
    myLinkedStack.push(7);
    myLinkedStack.push(8);
    myLinkedStack.printStack();  // выводим стек
    cout << myLinkedStack.pop() << endl;   // выводим элемент из myLinkedStack и удаляем этот элемент
    myLinkedStack.printStack();  // выводим стек

}
