## アルゴリズム

ある処理を行うプログラムを作成するときに、どのような計算を行っていくかという計算手順のことをアルゴリズムといいます。

## 計算時間と記憶領域

メモリは有限であり、変数を使用した分だけメモリを消費します。 
文字列や配列の変数は内部の要素数に応じてメモリを消費します。
例えば、int型のN要素の配列はN個のint型の変数を使用したのと同じくらいのメモリを消費します。 
同様に長さNの文字列はN個のchar型の変数を使用したのと同じくらいのメモリを消費します。

## 計算量

プログラムは入力に対して必要な計算を行い、結果を出力します。 
このときに必要な計算時間や必要な記憶領域の量が、入力に対してどれくらい変化するかを示す指標を計算量といいます。
計算量には時間計算量と空間計算量があります。単に計算量という場合、時間計算量を指すことが多いです。

### 時間計算量

### 空間計算量

### 計算量の例

```cpp
#include <bits/stdc++.h>
using namespace std;
 
// 1からNまでの総和(1+2+3+⋯+N)を計算するもの
int main() {
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += i;
  }
  cout << sum << endl;
}
```

for文でN回の繰り返し処理を行っているので、計算ステップ数は入力のNに応じて変わります。
N回の繰り返しを行うので、計算ステップ数はおおよそN回になります。
このときの時間計算量は次で紹介するオーダー記法を用いてO(N)と表します。
変数は入力のNに関わらず `int N` と `int sum` と `int i` の3つです。

### オーダー記法

