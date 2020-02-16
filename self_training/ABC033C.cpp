#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

string s;
vector<long long int> after_mul;
long long int ans;
long long int tmp;

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
    cin >> s;
    tmp=1;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='*'){
            // NOP
        }else if(s[i]=='+'){
            //tmp計算を打ち切る
            after_mul.push_back(tmp);
            tmp = 1;
        }else if(s[i]== '0') {
            tmp = 0;
        }
// 9の5万乗だとよゆうであふれることに注意する
//        }else{
//            tmp *= calc_val(s[i]);
//        }

        if(i == (s.size()-1)){ //末尾処理
            after_mul.push_back(tmp);
            tmp = 1;
        }
    }

    // 0でない数を計算
    for(int i=0; i<after_mul.size(); i++){
        if(after_mul[i] != 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}