// 「ビット全探索」と呼ばれるテクニックを紹介します。

// ビット全探索によって、組合せの全列挙をシンプルに実装することができます。

// ビット全探索とは「すべてのビット列の組合せ」に対して何らかの処理を行うことをいいます。

// 例えば、長さ2のビット列ならば、すべてのビット列の組合せは「00」「01」「10」「11」の4通りです。

// 各ビットについて0か1の2通りなので長さNのビット列は2N通り存在します。

// 次のサンプルプログラムでは、すべての「長さ3のビット列」を列挙しています。

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // 3ビットのビット列をすべて列挙する
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    // ビット列を出力
    cout << s << endl;
  }
}

// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111