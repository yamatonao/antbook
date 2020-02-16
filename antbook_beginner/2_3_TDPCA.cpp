#include <iostream>
#include <algorithm>  // std::sort, std::unique
#include <vector>
using namespace std;

int n=0;
int p[101]={0};
int seen[101][ (100*100) + 10] ={0};

vector<int> ans;

int dfs(int i, int points){
    if(seen[i][points] == 1){ //すでに一度でも以後計算済み？
        return 0;
    }

    if(i >= n){//最下層なら
        ans.push_back(points);
        return 0;
    }

    {   //加算するなら
        dfs(i+1, points+p[i]);
    }
    {   //加算しないなら
        dfs(i+1, points);
    }

    seen[i][points] = 1; //訪問済みにする
    return 0;
}

int main(void){
    //input
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    dfs(0,0);

    //重複削除して数出せばok
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()),ans.end());
    cout << ans.size() << endl;

    return 0;
}