#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data(5);

    for (int i = 0; i < 5; i++) {
        cin >> data.at(i);
    }

    bool judgment = false;

    for (int i = 0; i < 4; i++) {
        if (data.at(i) == data.at(i + 1)) {
            judgment = true;
        } 
    }

    if (judgment) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}