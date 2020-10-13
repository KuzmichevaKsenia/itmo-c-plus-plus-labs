#include <iostream>

using namespace std;

// линейный однонаправленный список
struct Node {
    int element;
    Node *next;

    Node(int element, Node *next = 0) { // конструктор узла
        this->element = element;
        this->next = next;
    }
};

class SingleList {

    Node *head; // головной узел
    int size; // размерность списка

    void printNodes(Node *curNode) { // печать всех элементов списка
        if (curNode != 0) {
            cout << curNode->element << " ";
            printNodes(curNode->next);
        } else {
            cout << endl;
        }
    }

    Node *prevNodeSearch(int n) { // поиск узла, предшествующего n-му
        return getNode(n - 1);
    }

    Node *getNode(int n) {
        if (n < 1 || n > size) {
            cout << "Ошибка: выход за пределы списка" << endl;
            return 0;
        }

        Node *result = head;
        while (--n) {
            result = head->next;
        }

        return result;
    }

public:

    SingleList() { // конструктор списка
        head = 0;
        size = 0;
    }

    void pushFront(int elem) { // добавить в начало
        Node *newHead = new Node(elem, head);
        head = newHead;
        cout << "Добавлен 1-й элемент со значением " << elem << endl;
        ++size;
    }

    void pushBack(int elem) { // добавить в конец
        Node *lastNode = getNode(size);
        Node *newNode = new Node(elem);
        lastNode->next = newNode;
        cout << "Добавлен " << size + 1 << "-й элемент со значением " << elem << endl;
        ++size;
    }

    void insert(int elem, int n) { // добавить новый элемент на n-ое место
        if (n < 1 || n > size + 1) {
            cout << "Невозможно выполнить операцию" << endl;
            return;
        }
        if (n == 1) {
            pushFront(elem);
        } else if (n == size + 1) {
            pushBack(elem);
        } else {
            Node *prevNode = prevNodeSearch(n);
            Node *shiftNode = prevNode->next;
            Node *newNode = new Node(elem, shiftNode);
            prevNode->next = newNode;
            cout << "Добавлен " << n << "-й элемент со значением " << elem << endl;
            ++size;
        }
    }

    int popFront() { // удалить с начала
        int result = head->element;

        Node *oldNode = head;
        head = head->next;
        delete oldNode;
        --size;
        cout << "Удален 1-й элемент со значением " << result << endl;
        return result;
    }

    int popBack() { // удалить с конца
        Node *prevNode = prevNodeSearch(size);
        int result = prevNode->next->element;
        delete prevNode->next;
        prevNode->next = 0;
        --size;
        cout << "Удален " << size << "-й элемент со значением " << result << endl;
        return result;
    }

    int remove(int n) { // удалить n-й элемент
        if (n < 1 || n > size) {
            cout << "Невозможно выполнить операцию" << endl;
            return 0;
        }

        if (n == 1) {
            return popFront();
        } else if (n == size) {
            return popBack();
        }

        Node *prevNode = prevNodeSearch(n);
        Node *oldNode = prevNode->next;
        int result = oldNode->element;
        prevNode->next = oldNode->next;
        delete oldNode;

        cout << "Удален " << n << "-й элемент со значением " << result << endl;
        --size;
        return result;
    }

    void printList() {
        cout << "Все элементы списка: ";
        printNodes(head);
    }

    void sizeOfList() {
        cout << "В списке элементов: " << size << endl;
    }

    DeleteAll() { // деструктор
        Node *curNode = head;
        head = 0;
        size = 0;
        while (curNode != 0) {
            Node *nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
        cout << "Все элементы удалены" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SingleList List = SingleList(); // создали новый список List

    List.insert(1, 1); // 1
    List.insert(3, 2); // 1 3
    List.insert(2, 2); // 1 2 3
    List.insert(5, 0); // 1 2 3
    List.insert(4, 1); // 4 1 2 3
    List.remove(1); // 1 2 3
    List.remove(3); // 1 2
    List.sizeOfList(); // 2
    List.printList(); // 1 2

    List.popBack(); // 1
    List.popFront(); //
    List.pushFront(8); // 8
    List.pushBack(23); // 8 23
    List.pushFront(49); // 49 8 23
    List.sizeOfList(); // 3
    List.printList(); // 49 8 23

    List.DeleteAll();
    List.printList();
}
