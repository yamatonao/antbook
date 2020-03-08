#include <iostream>
#include <vector>

using namespace std;

//#define COM_MAX (510000)
#define MOD (1000000007)
//long long fac[COM_MAX];
//long long finv[COM_MAX];
//long long inv[COM_MAX];
//
//void COMinit(void){
//    // 法MOD での二項係数出す準備
//    fac[0] = fac[1] =1;
//    finv[0] = finv[1] =1;
//    inv[1] = 1;
//    for(int i=2; i< COM_MAX; i++){
//        fac[i]  = fac[i - 1] * i % MOD;
//        inv[i]  = MOD - inv[MOD%i] * (MOD / i) % MOD;
//        finv[i] = finv[i - 1] * inv[i] % MOD;
//    }
//
//    return;
//}
//
//long long COM(int n, int k){
//    if(n<k ){return 0;}
//    if(n<0 || k < 0 ){return 0;}
//    return fac[n]* (finv[k]* finv[n-k] % MOD) % MOD;
//}
//


// a^n (mod p)
long long modpow(long long a, long long n, long long p){
    //二分累乗法
    long long res=1;
    while(n>0){
        if(n&1){
            // x^2^0, x^2^1, ...が必要(指数を2^x乗で分解したときに存在する)ならかける
            res = res * a % p; // 乗算なので常時mod取ってok
        }
        // x^2^1, x^2^2..を順番に作っていく
        a = a*a % p;  // 乗算なので常時mod OK
        n >>= 1;
    }
    return res;
}


long long COM(long long n, long long k){
    long long a=1;
    long long b=1;
    long long div=0;

    for(long long int i=0; i< k; i++){
        a = (a*(n-i)) % MOD;
    }
    for(long long int i=1; i<= k; i++){
        b = (b*i) % MOD;
    }
    div = modpow(b, MOD-2 ,MOD);

    return (a*div) %MOD;
}

int main(void){
    long long int n;
    long long int a;
    long long int b;

    long long int base;
    long long int nca;
    long long int ncb;

    cin >> n;
    cin >> a;
    cin >> b;

    // おまじない
//    COMinit();
    // 2^n-1
    base = modpow(2, n, MOD)-1;
//    cout << base << endl;
    nca = COM(n,a);
//    cout << nca << endl;
    ncb = COM(n,b);
//    cout << ncb << endl;

    base = base-nca;
    if(base < 0){base += MOD;}
    base = base-ncb;
    if(base < 0){base += MOD;}

    cout << base << endl;

    return 0;
}

