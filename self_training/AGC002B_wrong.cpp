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

ll x[100010];
ll y[100010];
ll box[100010];
vector<ll> ans;

    ll m;
void dfs(ll red_pos, ll level){
//    cout << red_pos << endl;
    level--;
    if(level == 0){
        ans.push_back(red_pos);
        return;
    }

    if(x[m-(level+0)] != red_pos){
        box[x[m-(level+0)]]--;
        box[y[m-(level+0)]]++;
        dfs(red_pos, level);
        box[x[m-(level+0)]]++;
        box[y[m-(level+0)]]--;
    }else{
        if(box[x[m-(level+0)]] == 1){
            box[x[m-(level+0)]]--;
            box[y[m-(level+0)]]++;
            dfs(y[m-(level+0)], level);
            box[x[m-(level+0)]]++;
            box[y[m-(level+0)]]--;
        }else{
            box[x[m-(level+0)]]--;
            box[y[m-(level+0)]]++;
            dfs(y[m-(level+0)], level);
            dfs(red_pos, level);
            box[x[m-(level+0)]]++;
            box[y[m-(level+0)]]--;
        }
    }
}

int main(void){
    ll n;
    cin >> n >> m;
    REP(i, m){
        ll tmp1;
        ll tmp2;
        cin >> tmp1 >> tmp2;
        x[i] = tmp1;
        y[i] = tmp2;
    }

    REP(i,100010){
        box[i] = 1;
    }

    dfs(1, m+1);

    sort(ALL(ans));
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << endl;

    return 0;
}