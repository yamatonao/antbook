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

ll a[200010];
ll d[200010];
ll ans_arr[2050];

int main(void){
    string s;
    cin >> s;
    reverse(ALL(s));

      /* 理屈はa[i]に応じたd[i]を求めにいくのだが、普通にofする
    REP(i,s.size()){
        ll tmp1 = (s[i] - '0');
        ll tmp2 =  pow(10, i);
        a[i] = ( tmp1* tmp2 ) % 2019;
    }
    REP(i,s.size()){
        if(i==0){
            d[0] = a[0] % 2019;
            // cout << d[0] << " ";
            continue;
        }
        d[i] = (d[i-1]+a[i])%2019;
            // cout << d[i] << " ";
    }
            // cout << endl;
    */

    // OF対策のためMOD界
    ll tmp2 =  1;
    REP(i,s.size()){
        ll tmp1 = (s[i] - '0');
        a[i] = ( tmp1* tmp2 ) % 2019;
        tmp2 *= 10;
        tmp2 %= 2019;
    }
    REP(i,s.size()){
        if(i==0){
            d[0] = a[0] % 2019;
            continue;
        }
        d[i] = (d[i-1]+a[i])%2019;
    }
            
    // 直接 d[i]を求めに行く。OF対策のため以降MOD界
    // 4
    // 14
    // 114
    // 2114
    // 12114
    // ...
    /*
    ll cur = 0;
    ll x = 1;
    REP(i, s.size()){
        ll tmp1 = (s[i] - '0');
        cur = (cur + (x*tmp1)  ) % 2019;
        d[i] = cur;
        x = x*10 %2019; // 永遠に10倍するとofなのでMOD界の割り算を考える
    }
    */

    REP(i,s.size()+1){
        ans_arr[ d[i] ] ++;
    }
    ll ans = 0;
    REP(i, 2050){
        if(ans_arr[i] >1){
            ll tmp =ans_arr[i] * (ans_arr[i]-1)  /2;
            ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}