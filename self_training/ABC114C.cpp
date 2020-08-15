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

ll ans;
string n;
ll selected_753[3];
char debug[4];

void BFS(ll level, bool state, bool zero_state){
    // 0のときの処理
    if(level == 0){
        if(selected_753[0] == 0 || selected_753[1] == 0 || selected_753[2] == 0){
            return;
        }else{
            //cout << debug << endl;
            //cout << selected_753[0] << " " << selected_753[1] << " " << selected_753[2]  << endl;
            ans++;
            return;
        }
    }

    // 0ではないときの処理
    //7
        if( (n[n.size()-level] - '0')>=7 || state){
            selected_753[0]++;

            bool tmp_flg = false;
            if((n[n.size()-level] - '0') > 7  && (! state)){
                state = true;
                tmp_flg = true;
            }
            debug[n.size()-level] = '7';
            BFS(level -1, state, false);
            if(tmp_flg){
                state = false;
            }
            selected_753[0]--;
        }
    //5
        if((n[n.size()-level] - '0')>=5 || state){
            selected_753[1]++;
            bool tmp_flg = false;
            if((n[n.size()-level] - '0')> 5  && (! state)){
                state = true;
                tmp_flg = true;
            }
            debug[n.size()-level] = '5';
            BFS(level -1, state, false);
            if(tmp_flg){
                state = false;
            }
            selected_753[1]--;
        }
    //3
        if((n[n.size()-level] - '0')>=3 || state){
            selected_753[2]++;
            bool tmp_flg = false;
            if((n[n.size()-level] - '0')> 3  && (! state)){
                state = true;
                tmp_flg = true;
            }
            debug[n.size()-level] = '3';
            BFS(level -1, state, false);
            if(tmp_flg){
                state = false;
            }
            selected_753[2]--;
        }
    //0
    if(zero_state){
            debug[n.size()-level] = '0';
            BFS(level -1, true, true);
    }
    return;
}


int main(void){
    cin >> n;
    string debug;
    BFS(n.size(), false, true);
    cout << ans << endl;
    return 0;
}