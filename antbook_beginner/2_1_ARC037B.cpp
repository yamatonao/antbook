#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
using Graph = vector<vector<int> >;
Graph G;
int seen[1000];
int ans;

int ng_flag;

void dfs(int no, int from){
    seen[no] = 1;
    for(int i=0; i< G[no].size(); i++){
        if (G[no][i]== from){
            continue;
        }
        if( !(seen[ (G[no][i]) ]) && (G[no][i]!= from)){
            dfs( G[no][i], no );
        }else{ // 閉路を発見した場合
            ng_flag = true;
        }
    }

    return;
}

int main(void){
    // input 受ける
    cin >> n;
    cin >> m;

    G.resize(n);
    for (int i=0; i< m; i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    //
    for(int i=0; i<n; i++){
        if(seen[i] == 0){
            dfs(i, -1);
            if(ng_flag){
                ng_flag =0;
            }else{
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}