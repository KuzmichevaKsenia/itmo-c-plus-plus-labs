/*
 * На вход подается число. Если это 3, вывести 5. Если это 5, вывести 3
 * */

#include <iostream>;

using namespace std;

int main() {
    int a;
    cin >> a;
    if (a == 3) a = 5;
    else if (a == 5) a = 3;
    cout << a;
    return 0;
}
