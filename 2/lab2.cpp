#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream cin("input2.txt");
    ofstream cout("output2.txt");
    double a, b, c;
    int Xbeg, Xend, dX;
    cin >> a >> b >> c >> Xbeg >> Xend >> dX;
    cout << "x  F" << endl;
    while (Xbeg <= Xend) {
        if ((Xbeg < 0) && (b != 0))
            cout << Xbeg << " " << a * Xbeg * Xbeg + b << endl;
        else if ((Xbeg > 0) && (b == 0)) {
            if (Xbeg - c == 0)
                cout << "делитель равен 0 " << endl;
            else
                cout << Xbeg << " " << (Xbeg - a) / (Xbeg - c) << endl;
        } else if (c != 0)
            cout << Xbeg << " " << (Xbeg / c) << endl;
        else
            cout << "делитель равен 0 \n" << endl;
        Xbeg = Xbeg + dX;
    }
    return 0;
}
