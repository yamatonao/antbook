#include <iostream>
#include <string>

using namespace std;

string s;
char depth[10];
long long int ans =0;

void solve(int pos){
   if( pos == (s.size()-1) ){    //最下層到達なら
       long long int sum = 0;
       long long int num = 0;
       string local_s;
               local_s.clear();
       for(int i=0; i< (s.size() -1); i++){
           local_s += s[i];
           if(depth[i] == 1){
//               cout << "tmp1" << endl;
               ans += stol(local_s);
//               cout << ans <<endl;
               local_s.clear();
           }
           if(i == (s.size() -2)){ // 末尾だけの特別処理
               local_s += s[ s.size() -1 ];
//               cout << "tmp2" << endl;
               ans += stol(local_s);
//               cout << ans <<endl;
           }
       }
       return;
   }

   // +を当てるなら
   { 
       depth[pos] = 1;
       solve(pos + 1);
   }
   { // +を当てないなら
       depth[pos] = 0;
       solve(pos + 1);
   }
   return;
}


int main(void){
   cin >> s;
   if(s.size() == 1){
   // size0は足したら終わり
       ans = stol(s);
   }else{
       solve(0);
   }
   cout << ans << endl;
   return 0;
}
