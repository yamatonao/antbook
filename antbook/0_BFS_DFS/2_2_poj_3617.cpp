#include <iostream>
int relinenum=0;

int N;
char S[2001];

void reline(void){
    relinenum++;
    if( (relinenum % 80) == 0 ){
        printf("\n");
    }
}

void input(void){
    scanf(" %d",&N);             //何故か改行コード不要
    for(int i=0; i< N; i++){
        scanf(" %c", &S[i]);
    }
    
//    for(int i=0; i< N; i++){
//        printf(" %c", S[i]);
//    }

    return;
}

void solve(){
    int a =0;
    int b= N-1;

    while(a<=b){ 
        //printf ("%d %d\n",a,b);
        bool left = false;

        // 右がすごいか左がすごいか計算。
        // 同じ時は次の文字を比較
        for(int i=0; a+i<= b; i++){
            if(S[a+i] < S[b-i]){
                left = true;
                break;
            }else if (S[a+i] > S[b-i]){
                left = false;
                break;
            }
        }
        if(left) {
            putchar(S[a++]);
            fflush(stdout);
            reline();
        }else {
            putchar(S[b--]);
            fflush(stdout);
            reline();
        }
    }
    return;
}

int main(void){
    input();
    solve();
    return 0;
}