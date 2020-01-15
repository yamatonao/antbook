#include <iostream>

int N;
int L[20000];

void input(void){
    scanf(" %d",&N);

    for(int i=0; i< N;i++){
        scanf(" %d",&L[i]);
    }
    return;
}

void solve(){
    long long int ans=0;
    //板が1になるまで適用
    while(N>1){
            // 一番短い板、次に短い板を求める。
            int mii1 =0;
            int mii2 = 1;
            if(L[mii1] > L[mii2]){
                std::swap(mii1,mii2);
            }

            for(int i=2; i<N; i++){ //配列最後まで走査する。
                if(L[i]< L[mii1]){
                    mii2 = mii1;
                    mii1 = i;
                }else if(L[i] < L[mii2]){
                    mii2 = i;
                }
            }
            // ここまでで求まった

            // それらをくっつける
            int t = L[mii1] + L[mii2];
            ans +=t; //切断コストを足しておく

            if(mii1 == N-1){
                std::swap(mii1,mii2);
            }
            L[mii1] = t;        // 合体した長さのやつ
            L[mii2] = L[N-1];   // 被合体を消滅させる
            N--;                // 合体して消滅したやつぶん、数を減らす
    }
    printf("%lld\n",ans);
    return;
}

int main(void){
    input();
    solve();
    return 0;
}