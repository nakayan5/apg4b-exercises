#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int average;

    average = ceil(((double)a + (double)b) / 2);

    cout << average << endl;
    return 0;
}