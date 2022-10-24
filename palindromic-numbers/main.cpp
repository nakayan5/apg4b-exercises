// 回文数をもとめる
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B; // 10000 ≤ A ≤ B ≤ 99999
    cin >> A >> B;

    int count = 0;

    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
        
                 int x = (10001 * a) + (1010 * b) + (100 * c);
                 
                 if (A <= x && x <= B) {
                     count++;
                 }
            
            }    
        }   
    }

    cout << count << endl;

    return 0;
}