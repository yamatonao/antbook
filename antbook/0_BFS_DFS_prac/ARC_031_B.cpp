// 写経answer

// default
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false;}

const long long INF = 1LL << 60;
char map[10][10] = {0};
static char tmp_map[10][10] = {0};
bool ans = false;

void input(void){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> map[i][j];
        }
    }
    return;
}

void init(void){
    return;
}

bool ans_check(void){
    //もし100マスすべて海になっていたなら正解なのでans = true で探索終わり
    for(int k=0; k<10; k++){
        for(int l=0; l<10; l++){
            if(tmp_map[k][l] == 'o'){
                return false;
            }
        }
    }

    return true;
}

void dfs(int i, int j){
    //いるところが海なら2マス目なので枝刈り
    if(tmp_map[i][j] == 'x'){
        return;
    }
    //今いるところを'x'に変える
    tmp_map[i][j] = 'x';

    //4方向精査 dfs
    if( i-1 >= 0){
        dfs(i-1, j);
    }
    if(j-1 >= 0){
        dfs(i, j-1);
    }
    if( i+1 <= 9){
        dfs(i+1, j);
    }
    if( j+1 <= 9){
        dfs(i, j+1);
    }
}

bool solve(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            // 探索用マップをリセット
            memcpy(tmp_map, map, 100);
            // もし、いるところが海ならば陸にしてBFS始動
            if(tmp_map[i][j] == 'x'){
                tmp_map[i][j] = 'o';
                dfs(i,j);
//
//            printf("\n");
//  for(int k=0; k<10; k++){
//        for(int l=0; l<10; l++){
//            if(tmp_map[k][l] == 'o'){
//                cout << "o";
//            }else{
//                cout << "x";
//            }
//        }
//            printf("\n");
//            fflush(stdout);
//   }
//
                if( ans_check() ){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    input();
    init();
    ans = solve();
    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}