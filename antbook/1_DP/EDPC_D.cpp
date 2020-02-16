// default
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

const long long INF = 1LL << 60;

int N;
long long W;
long long weight[110];
long long value[110];

long long dp[110][100100]={0};

void input(void){
    cin >> N >> W;
    for(int i=0; i< N; ++i){
        cin >> weight[i] >> value[i];
    }
    return;
}

void init(void){
    return;
}

void solve(){
    for(int i=0; i<N; ++i){
        for(int sum_w=0; sum_w <= W; ++sum_w){

            // i番目の品物を選ぶ場合
            if( (sum_w - weight[i]) >= 0){ //そもそもテンポラリサイズより余ってないとだめ
                
                // 更新先のマスに元からある値と、
                // 今いるマスの価値にからweightを引いたやつ（サイズが空いているところに価値を足したやつ）
                // 比較して大きいなら更新
                chmax(  dp[i+1][sum_w], 
                        dp[i][sum_w - weight[i]] + value[i]
                        );
            }
                //選ばないときは、そのままの値を表の下におろせるか確認する。
                chmax(  dp[i+1][sum_w],
                        dp[i][sum_w]
                        );


        }
    }
    cout << dp[N][W] << endl;
    return;
}

int main(void){
    input();
    init();
    solve();
    return 0;
}