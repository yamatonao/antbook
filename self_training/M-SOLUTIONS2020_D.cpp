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

ll dp_stock[100];
ll dp_stock_mod_money[100];
ll dp_money[100];

int main(void){
    ll n;
    vector<ll> input;
    cin >> n;
    REP(i,n){
        ll tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    dp_money[0] = 1000;
    dp_stock[0] = (dp_money[0]/input[0]);
    dp_stock_mod_money[0] = dp_money[0]%input[0];

    REP(i,n){
        if(i==0){continue;}
        // money更新
        CHMAX(dp_money[i], dp_money[i-1]);
        CHMAX(dp_money[i], (dp_stock[i-1]*input[i])+dp_stock_mod_money[i-1]);
        // stock更新
        ll stock_base       =dp_stock[i-1];
        ll stock_mod_base   =dp_stock_mod_money[i-1];
        ll stock_tmp        =dp_money[i-1]/input[i];
        ll stock_mod_tmp    =dp_money[i-1]%input[i];
        if(stock_tmp > stock_base){
            dp_stock[i]= stock_tmp;
            dp_stock_mod_money[i] = stock_mod_tmp;
        }else if(stock_tmp == stock_base && stock_mod_tmp > stock_mod_base){
            dp_stock[i]= stock_tmp;
            dp_stock_mod_money[i] = stock_mod_tmp;
        }else{ //前回値のほうが良い
            dp_stock[i]= stock_base;
            dp_stock_mod_money[i] = stock_mod_base;
        }

    }

    cout << dp_money[n-1] << endl;

    return 0;
}