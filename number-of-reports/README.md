# 再帰関数

再帰とは「ある関数の中で同じ関数を呼び出す」ことです。
また、このような関数のことを再帰関数といいます。
再帰はループ構文よりも強力な繰り返し手法で、ループ構文で書くのが難しいような処理を簡潔に行うことができます。

[再帰関数の動作](https://www.slideshare.net/APG4b/apg4b-205-sum)

## 再帰関数の性質

再帰関数の内容は大きく分けると以下の 2 つの処理に分類できます。

- **ベースケース** ：再帰呼び出しを行わずに完了できる処理
- **再帰ステップ** ：再帰呼出しを行い、その結果を用いて行う処理

また、再帰関数が正しく動作するためには次の条件を満たす必要があります。

- 再帰呼び出しの連鎖に終わりがある

これを言い換えると、「再帰ステップでの再帰呼び出しを繰り返すうちに必ずベースケースに到達する」ということになります。

## 再帰関数の実装法

1. ### 「引数」「返り値」「処理内容」を決める

2. ### 再帰ステップの実装

3. ### ベースケースの実装 （再帰呼び出しを行わずに完了できる処理）

## 例

### sum_range

```cpp
#include <bits/stdc++.h>
using namespace std;

// a ~ bの総和を計算する (a ≦ b)という前提
int sum_range(int a, int b) {
  // ベースケース
  if (a == b) {
    return a;
  }
  // 再帰ステップ
  return sum_range(a, b - 1) + b;  //「a~bの総和」=「a~(b-1)の総和」+ b
}

int main() {
  cout << sum_range(0, 4) << endl; // 0 + 1 + 2 + 3 + 4 = 10
}

// output
sum_range(0, 4-1) -> 4
sum_range(0, 3-1) -> 3
sum_range(0, 2-1) -> 2
sum_range(0, 1-1) -> 1
sum_range(0, 0-1) -> 0
```

### array_sum

```cpp
#include <bits/stdc++.h>
using namespace std;

// (補助関数)
// dataのi番目以降の要素の総和を計算する
int array_sum_from_i(vector<int> &data, int i) {
  // ベースケース
  if (i == data.size()) return 0;  // 対象の要素がないので総和は0

  // 再帰ステップ
  int s = array_sum_from_i(data, i + 1);  // i+1番目以降の要素の総和
  return data.at(i) + s;  // 「i番目以降の要素の総和」=「i番目の要素」+ s
}

// dataの全ての要素の総和を計算する
int array_sum(vector<int> &data) {
  return array_sum_from_i(data, 0);
}

int main() {
  vector<int> a = {0, 3, 9, 1, 5};
  cout << array_sum(a) << endl;   // 0 + 3 + 9 + 1 + 5 = 18
}

// output
array_sum_from_i(data, 0 + 1)を呼び出す -> array_sum_from_i(data, 1 + 1) -> array_sum_from_i(data, 2 + 1) -> array_sum_from_i(data, 3 + 1) -> array_sum_from_i(data, 4 + 1)

data.at(5) -> data.at(4) + 0 -> data.at(3) + (0+5) -> data.at(2) + (0+5+1) -> data.at(1) + (0+5+1+9) -> data.at(0) + (0+5+1+9+3) -> 0+5+1+9+3+0 -> 18

array_sum_from_i(data, 4 + 1)の返り値は0
```
