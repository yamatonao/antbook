#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;

int main(void){
    ll a;
    ll b;
    ll c;
    cin >> a;
    cin >> b;
    cin >> c;

    ll outer = a+ b+ c;
    ll inner = 0;
    // a+b-c
    // a-b+c
    // a-b-c
    // -a+b-c
    // -a-b+c のどれかから、絶対値が一番小さいものを選ぶ
    if( (a+b >=c) && ((a+c)>= b )&& (c+b)>= a){
        inner = 0;
    }else{
        // 三角形を作れるなら
        inner = abs(a+b-c);
        if(inner > abs(a-b+c) ){ inner = abs(a-b+c);}
        if(inner > abs(a-b-c) ){ inner = abs(a-b-c);}
        if(inner > abs(-a+b-c) ){ inner = abs(-a+b-c);}
        if(inner > abs(-a-b+c) ){ inner = abs(a-b+c);}
    }


    //cout << inner << endl;

    long double douter = outer;
    long double dinner = inner;
    long double ans = douter * douter * 3.141592653589793;
    ans -= dinner * dinner * 3.141592653589793;

    printf("%.10Lf\n",
     ans);


    return 0;
}