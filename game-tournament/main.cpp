// コンパイルエラーが出る
// https://atcoder.jp/contests/apg4b/tasks/APG4b_ce

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N, M; // N人が参加しM試合が行われる
    cin >> N >> M;
    vector<int> A(M), B(M); // 試合1で勝った人の番号A1, 試合1で負けた人の番号B1 
    for (int i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    // row：横が自分, column：縦が相手
 
    // ここにプログラムを追記
    // (ここで"試合結果の表"の2次元配列を宣言)
    vector<vector<int>> data(N, vector<int>(N)); // N ✖️ Nのtable　※おそらく-で初期化しているからコンパイルエラーが出る

    // 勝ちの処理
    for (int i = 0; i < N; i++) {
        int atMe = A.at(i) - 1;
        int atOpponent = B.at(i) - 1;
        data.at(atMe).at(atOpponent) = 2;
    }

    // 負けの処理
    for (int i = 0; i < N; i++) {
        int atMe = B.at(i) - 1;
        int atOpponent = A.at(i) - 1;
        data.at(atMe).at(atOpponent) = 1;
    }

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            if (b == N - 1) {
                if (data[a][b] == 2) {
                    cout << "○";
                } else if (data[a][b] == 1) {
                    cout << "x";
                } else {
                    cout << "-";
                }
            } else {
                if (data[a][b] == 2) {
                    cout << "○" << " ";
                } else if (data[a][b] == 1) {
                    cout << "x" << " ";
                } else {
                    cout << "-" << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}