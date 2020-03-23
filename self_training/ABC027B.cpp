#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;

int main(void){
    ll n;
    ll ave=0;
    cin >>n;
    vector<ll> a;
    for(ll i=0; i<n; i++){
        ll tmp;
        cin >>tmp;
        a.push_back(tmp);
        ave += tmp;
    }


    if( (ave % n) != 0){
        cout << -1 <<endl;
        return 0;
    }
    ave = ave/n;

    ll tmp=0;
    ll num=0;
    ll ans =0;
    for(ll i=0; i<n; i++){
        tmp+=a[i];
        num++;
            if( (num*ave) == tmp){
                tmp=0;
                num=0;
            }else{
                ans++;
            }
    }
    cout << ans << endl;

    return 0;
}