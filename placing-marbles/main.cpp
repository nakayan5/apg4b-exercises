#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> s(3);
    cin >> s[0] >> s[1] >> s[2];
    int count = 0;

    for (int i = 0; i < 3; i++) {
        if (s[i] == 1) count += 1;
    }
    
    cout << count << endl;
    return 0;
}