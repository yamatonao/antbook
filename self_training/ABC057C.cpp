//写経
//順番に約数をうつしていって
//半分超えたところで終わり。

#include <iostream>
#include <vector>
using namespace std;

int cnt_digits(long long n){
    int digits =0;
    while(n>0){
        n /=10;
        digits++;
    }

    return digits;
}

int main(void){
    long long n;
    cin >> n;

    int ans=cnt_digits(n);

    for(long long a= 1 ; a*a <=n; ++a ){
        if(n%a != 0){
            continue;
        }

        const long long b=n/a;

        const int cur=max(cnt_digits(a), cnt_digits(b));

        if(ans > cur){
            ans= cur;
        }
    }

    cout << ans << endl;
    return 0;
}
