// 全探索のメモ化 → 全探索ツリーをメモ化しながら入れていく
// 漸化式として捉え、それを実装する。
// 今回は

/*
dp[i][j] = i問目までの問題を使って、j点の合計点ができるかどうかの真理値と設定する。
(ナップサック問題はiまでの荷物を使ってsum_wまでの価値最大値として設定)

dp[i][j]
    = dp[i-1][j] ∨ dp[i-1][j-Pi] (j >= Pi)
    = dp[i-1][j] (j < Pi) (すでに単体でjを超えてたらできるわけない)

*/

// 写経answer

// default
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

const long long INF = 1LL << 60;
int N;
int p[ 100+10 ] ;


void input(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> p[i];
    }
    return;
}

void init(void){
    return;
}

void solve(){
    vector<vector<bool> > DP(101, vector<bool>(10010, false));
    // vector型の変数 DPを定義
    // vectorには、 vector<bool>型が加わる
    // DPのサイズは101で。DP[i]には、[falseで初期化された10010個の要素を持つvector<bool>]がくっつく。
    // vector<int> A(101, x) <- 要素は 101個。xで初期化
    // DP[101][10010] = {false}; とほとんど等しい
    DP[0][0] = true;
    for(int i=1; i<=N; i++){
        for(int j=0; j< 10010; j++){
            if(j<= p[i-1]){
                DP[i][j] = DP[i-1][j] || DP[i-1][ j-p[i-1]];
            }else{
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    int count =0;
    for(int i=0; i< 10010; i++){
        couBnt += DP[N][i];
    }
    cout << count << endl;
    return;
}

int main(void){
    input();
    init();
    solve();
    return 0;
}