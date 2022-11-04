# 数値型

- 計算の途中で扱える範囲を超えることをオーバーフローといい、正しく計算が行えなくなる
- int 型より大きい値を扱いたいときは **int64_t 型** を使う
- double 型の値を出力する際に出力する小数点以下の桁数を指定するには以下のようにする
  `cout << fixed << setprecision(桁数);`

## int64_t 型

int 型が表せる範囲は以下の通りに限られています。

- 最小値：-2147483648
- 最大値：2147483647

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 2000000000;
  int b = a * 2;
  cout << b << endl; // -> -294967296  4000000000が出力されてほしいところですが、-294967296という値が出力されてしまっています。

  int c = (a * 10 + 100) / 100;
  cout << c << endl; // -> -14748363  2000000000 * 10の時点で計算結果がint型の範囲を超えてしまうので、正しくない答えが出る
}
```

もっと広い範囲の値を扱いたい場合、 **int64_t 型** を使うのが一般的です。int64_t 型で扱える値の範囲は以下のとおりです。

- 最小値：-9223372036854775808
- 最大値：9223372036854775807

プログラム中に直接 10 のように値を書くと、それは int 型の数値として扱われます。
int64_t 型として扱ってほしい場合は **10LL** のように末尾に **LL** をつけましょう。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << 2000000000 * 2 << endl;     // int * int         -> int (-294967296)
  cout << 2000000000LL * 2LL << endl; // int64_t * int64_t -> int64_t (4000000000)
  cout << 2000000000LL * 2 << endl;   // int64_t * int     -> int64_t (4000000000)
}
```

## double 型の出力

double 型を出力する場合、通常通り cout で出力してしまうと適当な桁で四捨五入されて表示されてしまいます。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << 3.14159265358979 << endl;  // -> 3.14159

  // 小数点以下10桁まで
  cout << fixed << setprecision(10);  // 途中の桁まで四捨五入せずに確実に表示したい場合、このように書きます。

  cout << 3.14159265358979 << endl;  // -> 3.1415926536
}
```

## printf での出力

精度指定を行う場合やたくさんの値を出力する場合には cout よりも printf 関数を使う方が便利です。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x = 12345;
  double pi = 3.14159265358979;
  printf("x = %d, pi = %lf\n", x, pi);  // -> x = 12345, pi = 3.141593
}
```

### フォーマット指定子

| 型      | フォーマット指定子 |
| ------- | ------------------ |
| int     | `%d`               |
| int64_t | `%ld（%lld）`      |
| double  | `%lf`              |
| char    | `%c`               |
| string  | `%s`               |

\*\* string 型は特殊

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "hello";
  // フォーマット指定子 %s を用い s.c_str() を渡す
  printf("%s\n", s.c_str()); // -> hello
}
```

## scanf での入力

`printf`とはポインタの有無の部分で異なる

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  double pi;
  // scanfによる入力
  scanf("x = %d, pi = %lf", &x, &pi);

  printf("x = %d, pi = %lf\n", x, pi);
}
```

## 文字列との変換

### to_string 関数

数値型から文字列に変換するには、to_string 関数を用いる

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int number = 100;
  string s = to_string(number);
  cout << s + "yen" << endl;  // -> 100yen
}
```

### stoi 関数

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "100";
  int n = stoi(s);
  cout << n << endl;  // -> 100
}
```

| 型      | 文字列からの変換関数 |
| ------- | -------------------- |
| int     | `stoi`               |
| int64_t | `stoll`              |
| double  | `stod`               |

## 他の数値型

追記
