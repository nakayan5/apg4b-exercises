# STLのコンテナ

## map

`map` は連想配列や辞書と呼ばれるデータ型です。
jsいうオブジェクトかな。

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  map<string, int> score;  // 名前→成績
  score["Alice"] = 100;
  score["Bob"] = 89;
  score["Charlie"] = 95;
 
  cout << score.at("Alice") << endl;   // Aliceの成績
  cout << score.at("Bob") << endl;     // Bobの成績
  cout << score.at("Charlie") << endl; // Daveの成績

  // scoreから「Bob→89」を削除する
  score.erase("Bob");
}
```

## queue

「値を1つずつ追加していき、追加した順で値を取り出す」ような処理を行うデータ構造をキューや待ち行列といいます。 C++では、STLに用意されている `queue` を用いることができます。

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  queue<int> q;
  q.push(10);
  q.push(3);
  q.push(6);
  q.push(1);
 
  // 空でない間繰り返す
  while (!q.empty()) {
    cout << q.front() << endl;  // 先頭の値を出力
    q.pop();  // 先頭の値を削除
  }

    // output
    // 10
    // 3
    // 6
    // 1

  q.push(); // 値を追加
  q.front(); // 先頭にアクセス
  q.pop(); // 先頭を削除
  q.size(); // 数を取得
  q.empty(); // 空かどうか判定
}
```

## priority_queue

「それまでに追加した要素のうち、最も大きいものを取り出す」という処理を行うときには、優先度付きキューというデータ構造を用います。 C++ではSTLの `priority_queue` を用いることができます。

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  priority_queue<int> pq;
  pq.push(10);
  pq.push(3);
  pq.push(6);
  pq.push(1);
 
  // 空でない間繰り返す
  while (!pq.empty()) {
    cout << pq.top() << endl;  // 最大の値を出力
    pq.pop();  // 最大の値を削除
  }

    // output
    // 10
    // 6
    // 3
    // 1
  
  pq.push() // 要素を追加
  pq.top() // 最大の要素の取得 queueとは異なる
  pq.pop() // 最大の要素を削除 queueとは異なる
  pq.size() // 数を取得
  pq.empty() // 空かどうか判定

}
```

### 最小の要素を取り出す

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  // priority_queue<型, vector<型>, greater<型>> 変数;
  // 小さい順に取り出される優先度付きキュー
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(10);
  pq.push(3);
  pq.push(6);
  pq.push(1);
 
  // 空でない間繰り返す
  while (!pq.empty()) {
    cout << pq.top() << endl;  // 最小の値を出力
    pq.pop();  // 最小の値を削除
  }
}
```

## stack

## deque

