// 写経AC

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//
const long long INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

int N;
long long h[100010];

//DP table
long long dp[100010];

void input(void){
    cin >> N;
    for(int i=0; i< N; i++){
        cin >> h[i];
    }
    return;
}

void init(void){
    for(int i=0; i< 100010; i++){
        dp[i]= INF;
    }
    return;
}

void solve(){
    //初期条件
    dp[0] = 0;

    // dp
    for(int i=1; i<N; i++){
        chmin(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        if(i>1){
            chmin(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
        }
    }

    cout << dp[N-1] << endl;
    return;
}

int main(void){
    input();
    init();
    solve();
    return 0;
}