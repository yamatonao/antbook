#include <iostream>
using namespace std;

int N=0;
int M=0;
char field[100][101] = {0};

void input(void){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> field[i][j];
        }
    }

    // output test
//    cout << endl;
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            printf("%c",field[i][j]);
//        }
//        cout << endl;
//    }
}

void dfs(int x, int y){
    // 今いるところを.に変える
    field[x][y] = '.';

    // 8方向走査
    for(int dx=-1;dx <= 1; dx++){
        for(int dy=-1;dy <= 1; dy++){
            int nx = x+dx;
            int ny = y+dy;

            if( 0 <= nx &&
                nx < N &&
                0 <= ny &&
                ny < M &&
                field[nx][ny] == 'W'
            ){
                dfs(nx, ny);
            }
        }
    }
    return ;
}

void solve(void){
    int res = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j] == 'W'){
                dfs(i,j);
                res++;
            }
        }
    }

    printf("%d",res);
    return;
}

int main(void){
    input();
    solve();
    return 0;
}


