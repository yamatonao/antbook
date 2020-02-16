#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R=0;
int C=0;
int sx=0;
int sy=0;
int ex=0;
int ey=0;
char map[50][50] = {0};
int map_distance[50][50] = {0};

queue<pair<int, int> > que;
pair<int, int>  pos;

int main(void){
    scanf("%d",&R);
    scanf("%d",&C);
    scanf("%d",&sx);
    scanf("%d",&sy);
    scanf("%d",&ex);
    scanf("%d",&ey);


    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            map_distance[i][j] = 100000;
        }
    }


    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
        }
    }

//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++){
//            cout << map[i][j];
//        }
//        cout << endl;
//    }


    map_distance[sx-1][sy-1] = 0;
    que.push(pair<int, int>(sx-1, sy-1)); // startをセット

    while(!que.empty()){
        pos = que.front();
        que.pop();

//        cout << pos.first << " " << pos.second << endl;
//                cout << "next_map" <<  map[pos.first][pos.second-1] << endl;
//                cout << "next_map" <<  map[pos.first][pos.second+1]<< endl;
//                cout << "next_map" <<  map[pos.first-1][pos.second] << endl;
//                cout << "next_map" <<  map[pos.first+1][pos.second]  << endl;

        //一つ上
        if( (pos.second-1 >= 0) && 
            map[pos.first][pos.second-1] == '.' ){
//                cout << "next_position" <<  pos.first << " " << pos.second-1 << endl;
            if(map_distance[pos.first][pos.second-1] == 100000){ //幅優先なので一度だけ探索
                map_distance[pos.first][pos.second-1] = map_distance[pos.first][pos.second]+1;
                que.push(pair<int, int>(pos.first, pos.second-1));
            }
        }
        //一つ下
        if( (pos.second+1 <= (C-1)) && 
            map[pos.first][pos.second+1] == '.'){
//                cout << "next_position" <<  pos.first << " " << pos.second+1 << endl;
            if(map_distance[pos.first][pos.second+1] == 100000){ //幅優先なので一度だけ探索
                map_distance[pos.first][pos.second+1] = map_distance[pos.first][pos.second]+1;
                que.push(pair<int, int>(pos.first, pos.second+1));
            }
        }
        //一つ左
        if( (pos.first-1 >= 0) && 
            map[pos.first-1][pos.second] == '.'){
//                cout << "next_position" <<  pos.first-1 << " " << pos.second << endl;
            if(map_distance[pos.first-1][pos.second] == 100000){ //幅優先なので一度だけ探索
                map_distance[pos.first-1][pos.second] = map_distance[pos.first][pos.second]+1;
                que.push(pair<int, int>(pos.first-1, pos.second));
            }
        }
        //一つ右
        if( (pos.first+1 <= (R-1)) && 
            map[pos.first+1][pos.second] == '.'){
//               cout << "next_position" <<  pos.first+1 << " " << pos.second << endl;
            if(map_distance[pos.first+1][pos.second] == 100000){ //幅優先なので一度だけ探索
                map_distance[pos.first+1][pos.second] = map_distance[pos.first][pos.second]+1;
                que.push(pair<int, int>(pos.first+1, pos.second));
            }
        }

//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++){
//            //cout << map_distance[i][j];
//            printf("%6d",map_distance[i][j]);
//            cout << " " ;
//        }
//            cout << endl ;
//    }
//            cout << endl ;

        //ゴールに到達？
        if(map_distance[ex-1][ey-1] != 100000){
            cout << map_distance[ex-1][ey-1] << endl;
            break;
        }
    }

    return 0;


}