//wrong answer

#include <iostream>
#include <string>
using namespace std;

long long int dp[2000][5];

string n;
long long int calc_val(char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

int main(void){
    int k;

    cin >>n;
    cin >>k;

    dp[1][1]= calc_val(n[0]);

    for(int i=1; i<=n.size();i++){
        dp[i][0]=1;
    }

/*
        for(int l=0; l<=n.size(); l++){
            for(int m=0; m<=k; m++){
                cout << " " << dp[l][m];
            }
            cout << endl;
        }
            cout << endl;
*/
    for(int i=1; i<=n.size(); i++){
        for(int j=1; j<=k; j++){
            if(i==1 && j==1){
                continue;
            }
            if(j>i){
                continue;
            }
            if(i==j){   //このときだけがN未満確定を表しているわけではない！！！
                dp[i][j] = max((long long)0, (calc_val(n[i-1]) ) + ( dp[i-1][j-1]-1) *9);
            }else{
                dp[i][j] = max((long long)0, dp[i-1][j] + dp[i-1][j-1] *9);
            }
/*
        for(int l=0; l<=n.size(); l++){
            for(int m=0; m<=k; m++){
                cout << " " << dp[l][m];
            }
            cout << endl;
        }
            cout << endl;
*/
        }
    }
    cout << dp[n.size()][k] << endl;
    return 0;
}