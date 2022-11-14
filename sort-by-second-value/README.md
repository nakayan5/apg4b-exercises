# pair/tuple

## pair

pairは2つの値の組を表す型です。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  pair<string, int> p("abc", 3);
  cout << p.first << endl;  // abc
 
  p.first = "hello";
  cout << p.first << endl;  // hello
  cout << p.second << endl; // 3
 
  string s;
  int a;
  tie(s, a) = p;
  cout << s << endl;  // *
  cout << a << endl;  // 1
}
```


## tuple

tupleはpairを一般化したもので、「複数個の値の組」を表す型です。

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  tuple<int, string, bool> data(1, "hello", true);
  get<2>(data) = false;
  cout << get<1>(data) << endl;  // hello
 
  data = make_tuple(2, "WORLD", true);
 
  int a;
  string s;
  bool f;
  tie(a, s, f) = data;
  cout << a << " " << s << " " << f << endl;  // 2 WORLD 1
}
```

## pair/tupleの比較

`pair<int, int>` を比較する場合、1番目の値を基準に比較され、もし1番目の値が等しい場合は2番目の値を基準に比較されます。

```cpp
  pair<int, int> a(3, 1);
  pair<int, int> b(2, 10);

  a < b は 3 < 2 を比較する
```

tupleを比較する場合もpairと同様に「1番目の値が最優先で比較され、等しい場合は2番目の値で比較する。もし2番目の値も等しい場合は3番目の値を比較する……」と、1番目の値から順に比較されます。

なお、`==` は全ての値が等しい場合、`!=` は1つ以上の異なる値が存在する場合にtrueとなります。

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<tuple<int, int, int>> a;
  a.push_back(make_tuple(3, 1, 1));
  a.push_back(make_tuple(1, 2, 100));
  a.push_back(make_tuple(3, 5, 1));
  a.push_back(make_tuple(1, 2, 3));
  sort(a.begin(), a.end());
 
  for (tuple<int, int, int> t : a) {
    int x, y, z;
    tie(x, y, z) = t;
    cout << x << " " << y << " " << z << endl;
  }
}

// まず、１番目を比較して２番目を比較して最後に３番目を比較する

// output
1 2 3
1 2 100
3 1 1
3 5 1
```

## auto

初期化を伴って変数を宣言する場合や範囲for文において、型の部分にautoと書くことによって型を省略することができます。

```cpp
#include <bits/stdc++.h>
using namespace std;
 
string concat(string a, string b) {
  return a + b;
}
 
int main() {
  string a = "Hello,";
  string b = "World";
  auto ab = concat(a, b);  // string型
  cout << ab << endl;
 
  vector<int> c = {1, 2, 3};
  auto d = c;  // vector<int>型
 
  for (auto elem : d) {
    // elemはint型
    cout << elem << endl;
  }
}
```