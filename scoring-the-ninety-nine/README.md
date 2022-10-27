# 参照

`参照先の型 &参照の名前 = 参照先;`で参照を宣言する。
基本的には宣言時に参照先を指定して初期化する必要がある点に注意してください。
また、 **あとから参照先を変更することはできません** 。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 3;
  int &b = a;  // bは変数aの参照

  cout << "a: " << a << endl;  // aの値を出力
  cout << "b: " << b << endl;  // bの参照先の値を出力(aの値である3が出力される)

  b = 4;  // 参照先の値を変更(aが4になる)

  cout << "a: " << a << endl;  // aの値を出力
  cout << "b: " << b << endl;  // bの参照先の値を出力(aの値である4が出力される)

    // output
    //   a: 3
    //   b: 3
    //   a: 4
    //   b: 4
}
```

## 関数の引数での参照

```cpp
#include <bits/stdc++.h>
using namespace std;

int g(int &x) {
  x = x * 2;  // xを2倍 (参照によって"呼び出す側の変数"が変更される)
  return x;
}

int main() {
  int a = 3;  // 関数を呼び出す側の変数
  int b = g(a);  // xの参照先がaになる
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
}

    // output
    // a: 6
    // b: 6
```

## 参照渡しの利点

### 1. 関数の結果を複数返したい

```cpp
#include <bits/stdc++.h>
using namespace std;

// a,b,cの最大値、最小値をそれぞれminimumの参照先、maximumの参照先に代入する
void min_and_max(int a, int b, int c, int &minimum, int &maximum) {
  minimum = min(a, min(b, c));  // 最小値をminimumの参照先に代入
  maximum = max(a, max(b, c));  // 最大値をmaximumの参照先に代入
}

int main() {
  int minimum, maximum;
  min_and_max(3, 1, 5, minimum, maximum);  // minimum, maximumを参照渡し
  cout << "minimum: " <<  minimum << endl;  // 最小値
  cout << "maximum: " <<  maximum << endl;  // 最大値
}

// output
// minimum: 1
// maximum: 5

// return で返さなくても複数の変数に代入できる！！！！
```

### 2. 無駄なコピーを減らす

```cpp
#include <bits/stdc++.h>
using namespace std;

// 配列の先頭100要素の値の合計を計算する
int sum100(vector<int> a) {
  int result = 0;
  for (int i = 0; i < 100; i++) {
    result += a.at(i);
  }
  return result;
}

int main() {
  vector<int> vec(10000000, 1);  // すべての要素が1の配列

  // sum100 を500回呼び出す
  for (int i = 0; i < 500; i++) {
    cout << sum100(vec) << endl;  // 配列のコピーが生じる
  }
}

// output runtime -> 7813 ms ！！！！
// 100
// 100
// 100
// 100
// 100
// (省略)
// ...
```

上のプログラムでは関数 **sum100** を呼び出すたびに配列の要素がコピーされるので、1000 万要素の配列のコピーが 500 回生じています。
この実行結果では全体で 7 秒以上の時間がかかっていて、配列を 1 回コピーするのに約 15 ミリ秒(0.015 秒)程かかっていることになります。

ここで、引数の `**vector<int> a**` を `**vector<int> &a**` として参照渡しするように変更します。

```cpp
#include <bits/stdc++.h>
using namespace std;

// 配列の先頭100要素の値の合計を計算する (参照渡し)
int sum100(vector<int> &a) {
  int result = 0;
  for (int i = 0; i < 100; i++) {
    result += a.at(i);
  }
  return result;
}

int main() {
  vector<int> vec(10000000, 1);  // すべての要素が1の配列

  // sum100 を500回呼び出す
  for (int i = 0; i < 500; i++) {
    cout << sum100(vec) << endl;  // 参照渡しなので配列のコピーは生じない
  }
}

// output runtime -> 15 ms ！！！！
// 100
// 100
// 100
// 100
// 100
// (省略)
// ...
```
