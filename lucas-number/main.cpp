// B - Lucas Number https://atcoder.jp/contests/abc079/tasks/abc079_b

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int64_t> L(N + 1);
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            L[i] = (int64_t)2;
        } else if (i == 1) {
            L[i] = (int64_t)1;
        } else {
            L[i] = (int64_t)L[i-2] + (int64_t)L[i-1];
        }
    }

    cout << L[N] << endl;

    return 0;
}