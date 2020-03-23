#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;

int main(void){
    ll n;
    cin >> n;

    vector<ll> ans;
    ll num=0;

    for(ll i=1; i<=n; i++){
        ans.push_back(i);
        num +=i;
        if(num >= n){
            num = (num-n);
            break;
        }
    }

    for(ll i=0; i<ans.size(); i++){
        if(ans[i] == num){continue;    }
        cout << ans[i] << endl;
    }

    return 0;
}