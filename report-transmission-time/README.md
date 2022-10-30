## 再帰関数の動作

```cpp
#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  if (n == 0) return 0;

  int s = sum(n - 1);
  return s + n;
}

cout << sum(3) << endl;

// output
sum(3-1) + 3
-> sum(2-1) + 2 + 3
-> sum(1-1) + 1 + 2 + 3
-> 0 + 1 + 2+ 3
```

```js
const factorial = (n: number): number => {
  if (n < 2) return 1;

  return n * factorial(n - 1);
};

factorial(4)

// output
4*factorial(4-1)
-> 4*(3*factorial(3-1))
-> 4*(3*(2*factorial(2-1)))
-> 4*(3*(2*(1)))
```

## 参考

- [再帰関数が苦手なエンジニアのための再帰関数入門](https://qiita.com/ryo2132/items/4bedeec846d0427f1ac7)
- [再帰関数を理解するための最もシンプルな例](https://qiita.com/saka2jp/items/20e6b5e70efa466699b4)
- [再帰関数を学ぶと、どんな世界が広がるか](https://qiita.com/drken/items/23a4f604fa3f505dd5ad)
- [末尾再帰による最適化](https://qiita.com/pebblip/items/cf8d3230969b2f6b3132)
- [JavaScript の末尾呼び出し最適化（TCO）](https://numb86-tech.hatenablog.com/entry/2017/01/03/215919)
