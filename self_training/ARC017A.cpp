// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define ALL(n) begin(n),end(n)
#define IN(a, x, b) (a<=x && x<b)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const long long MOD = 1000000007;

ll odd_num;
ll even_num;

int main(void){
    ll n;
    ll p;
    cin >> n >> p;
    REP(i,n){
        ll tmp;
        cin >>tmp;
        if(tmp % 2){
            odd_num++;
        }else{
            even_num++;
        }
    }
    ll ans=0;

    if(odd_num){
            ll ans = pow(2,n-1);
        cout << dec << ans << endl;
    }else{
        if(p){
            cout << "0" << endl;
        }else{
            ll ans = pow(2,n);
            cout << dec << ans << endl;
        }
    }
//    cout << ans << endl;
    /* ofsuru?
    if(p){
        // odd_numから奇数個 * even_num2^n
        ll num =1;
        while(1){
            if(odd_num<num){break;}
            ll tmp1 =1;
            ll tmp2 =1;
            for(ll i=1; i<=num; i++){
                tmp1 *= odd_num -(i-1);
                tmp2 *= i;
            }
            ans += (tmp1 / tmp2);
            num+=2;
        }
        ans *= pow(2, even_num);
    }else{
        // odd_numから偶数個 2,4,6,8,10...選ぶパターン累計 * even_numの2^n
        ll num=2;
        ans += 1;
        while(1){
            if(odd_num<num){break;}
            ll tmp1 =1;
            ll tmp2 =1;
            for(ll i=1; i<=num; i++){
                tmp1 *= odd_num -(i-1);
                tmp2 *= i;
            }
//            cout << tmp1 << tmp2 <<endl;
            ans += (tmp1 / tmp2);
            num+=2;
        }
        ans *= pow(2, even_num);
    }
    */
    return 0;
}