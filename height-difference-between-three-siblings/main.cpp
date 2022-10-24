#include <iostream>
#include <math.h>
using namespace std;


int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int x = max(max(A, B), C); // 最大値を計算
    int y = min(min(A, B), C); // 最小値を計算
    
    cout << x - y << endl;

    return 0;
 }