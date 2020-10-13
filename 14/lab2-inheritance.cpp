#include <iostream>

using namespace std;

class Element {
protected:
    char *name; //имя элемента (указатель на строку символов)
    int inputsNumber; //количество входов элемента
    int outputsNumber; //количество выходов элемента

public:
    Element(char *name = "No name", int inputsNumber = 0, int outputsNumber = 0) {
        this->name = name;
        this->inputsNumber = inputsNumber;
        this->outputsNumber = outputsNumber;
    }

    void setName(char *name) {
        this->name = name;
    }

    void setInputsNumber(int inputsNumber) {
        this->inputsNumber = inputsNumber;
    }

    void setOutputsNumber(int outputsNumber) {
        this->outputsNumber = outputsNumber;
    }
};

class Combination : public Element { // двоичный вентиль с 3 входами и 1 выходом
    bool inputValue[3];

public:
    Combination(char *name = "No name") :
            Element(name, 3, 1) {
        for (int i = 0; i < 3; ++i) inputValue[i] = false;
    }

    Combination(Combination const &other) {
        name = other.name;
        inputsNumber = other.inputsNumber;
        outputsNumber = other.outputsNumber;
        for (int i = 0; i < 3; ++i) inputValue[i] = other.inputValue[i];
    }

    void setInputValues(bool *inputValue) {
        for (int i = 0; i < 3; ++i) this->inputValue[i] = inputValue[i];
    }

    bool getInputValue(int index) {
        return inputValue[index];
    }

    bool nand() {  // элемент и-не
        for (int i = 0; i < inputsNumber; ++i) {
            if (inputValue[i] == 0) return 1;
        }
        return 0;
    }
};

class Memory : public Element { // триггер
    bool R;
    bool S;
    bool Q;
    bool nQ;

public:
    Memory() {
        R = 0;
        S = 0;
        Q = 0;
        nQ = 1;
    }

    Memory(Memory &other) {
        R = other.R;
        S = other.S;
        Q = other.Q;
        nQ = other.nQ;
    }

    void setRS(bool R, bool S) {
        this->R = R;
        this->S = S;
    }

    bool getR() {
        return R;
    }

    bool getS() {
        return S;
    }

    bool getQ() {
        return Q;
    }

    bool getnQ() {
        return nQ;
    }

    void calcQ() {
        if (R == 0 && S == 1) Q = 1;
        if (R == 1 && S == 0) Q = 0;
        nQ = !Q;
    }

    bool operator==(const Memory &other) {
        return Q == other.Q;
    }

    void printff() {
        cout << "Q is " << Q << ", nQ is " << nQ << endl;
    }

};


class Register { // 12-разрядный регистр на rs-триггерах
    Memory RSflipflop[12];

public:
    void setRSflipflop(Memory *RSflipflop) {
        for (int i = 0; i < 12; ++i)
            this->RSflipflop[i] = RSflipflop[i];
    }

    void printRegister() {
        for (int i = 0; i < 12; ++i) {
            cout << i << " flip-flop: " << endl;
            RSflipflop[i].printff();
            cout << endl;
        }
    }
};

int main() {
    Memory ff; // создаем триггер ff
    ff.setRS(0, 1);
    cout << "R is " << ff.getS() << ", S is " << ff.getR() << endl;
    ff.calcQ();
    ff.printff();
    cout << endl;

    Memory ff1; // создаем триггер ff1, сравниваем с ff по значению Q
    if (ff == ff1) cout << "outputs are equal" << endl;
    else cout << "outputs are not equal" << endl;
    cout << endl;

    Memory RSregister[12]; // создаем массив из триггеров ff
    for (int i = 0; i < 12; ++i) {
        RSregister[i] = ff;
    }
    Register reg;
    reg.setRSflipflop(RSregister);
    reg.printRegister();

    Combination comb("nand");
    Combination comb1(comb);
    bool in[3] = {1, 0, 1};
    comb1.setInputValues(in);
    cout << comb1.getInputValue(1) << endl; // вход вентиля по индексу 1
    cout << comb1.nand() << endl; // значение на выходе вентиля и-не
    return 0;
}
