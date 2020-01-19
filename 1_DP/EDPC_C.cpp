// default
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

const long long INF = 1LL << 60;

int N;
long long a[100010][3]; // a[i]b[i]c[i]をまとめる。
long long dp[10010][3];

void input(void){
    cin >> N;
    for(int i=0; i<N;i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }
    return;
}

void init(void){
    // nothing to do
    return;
}

void solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(j == k){
                    continue;   // 同じものは二度連続で選べない
                }
                chmax(dp[i+1][k],dp[i][j]+ a[i][k]);
            }
        }
    }
    long long res =0;
    for (int j = 0; j < 3; ++j) chmax(res, dp[N][j]);
    cout << res << endl;
    return;
}

int main(void){
    input();
    init();
    solve();
    return 0;
}