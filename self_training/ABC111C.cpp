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

int main(void){
    ll n;
    cin >> n;

    vector<pair<ll, ll> > odd;
    vector<pair<ll, ll> > even;

    REP(i,100010){
        odd.push_back(make_pair(0,i));
        even.push_back(make_pair(0,i));
    }

    ll need_num = n/2;
    FOR(i, 1, n+1){
        ll tmp;
        cin >> tmp;
        if(i%2 == 1){
            odd[tmp].first++;
        }else{
            even[tmp].first++;
        }
    }

    sort(ALL(odd), greater<pair<ll, ll> >());
    sort(ALL(even), greater<pair<ll, ll> >());

    ll odd_ans[2];
    odd_ans[0] = need_num - odd[0].first;
    odd_ans[1] = need_num - odd[1].first;

    // cout << odd_ans[0] << " " << odd_ans[1] << endl;

    ll even_ans[2];
    even_ans[0] = need_num - even[0].first;
    even_ans[1] = need_num - even[1].first;

    // cout << even_ans[0] << " " << even_ans[1] << endl;

    ll ans =0;
    if( odd[0].second == even[0].second){
        ans = odd_ans[0] + even_ans[1];
        CHMIN(ans, odd_ans[1] + even_ans[0]);
    }else{
        ans = odd_ans[0] + even_ans[0];
    }

    cout << ans << endl;

    return 0;
}