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

char ans[100010];
string s;

bool solve_common(void){
    bool badans = false ;
    char tmp;
    REP(i, s.size()){
        //cout << i << " "<< ans << endl;
        if(i ==0){
            continue;
        }
        if(ans[i] == 'S'){
            if(s[i] == 'o'){
                if( ans[i-1] == 'S' ){
                    tmp = 'S' ;
                }else if( ans[i-1] == 'W'){
                    tmp = 'W' ;
                }
            }
            if(s[i] == 'x'){
                if( ans[i-1] == 'S' ){
                    tmp = 'W' ;
                }else if( ans[i-1] == 'W'){
                    tmp = 'S' ;
                }
            }
        }else{
            if(s[i] == 'x'){
                if( ans[i-1] == 'S' ){
                    tmp = 'S' ;
                }else if( ans[i-1] == 'W'){
                    tmp = 'W' ;
                }
            }
            if(s[i] == 'o'){
                if( ans[i-1] == 'S' ){
                    tmp = 'W' ;
                }else if( ans[i-1] == 'W'){
                    tmp = 'S' ;
                }
            }
        }
    
        if(i==s.size()-2){
            if(ans[s.size()-1] != tmp){
                badans = true;
                break;
            }
             if( ans[s.size()-1] == 'S'){
                if( s[s.size()-1] == 'o' && ans[s.size()-2] != ans[0]){
                    badans = true;
                    break;
                }
                if( s[s.size()-1] == 'x' && ans[s.size()-2] == ans[0]){
                    badans = true;
                    break;
                }
                ans[i+1] =tmp;
                break;
            }else{
                if( s[s.size()-1] == 'o' && ans[s.size()-2] == ans[0]){
                    badans = true;
                    break;
                }
                if( s[s.size()-1] == 'x' && ans[s.size()-2] != ans[0]){
                    badans = true;
                    break;
                }
                ans[i+1] =tmp;
                break;
            }
        }else{
            ans[i+1] =tmp;
        }
    }

    return badans;
}

bool solve_1(void){
            ans[0] = 'S';
            if(s[0] == 'o'){
                ans[1] = 'S';
                ans[s.size()-1] = 'S';
            }
            if(s[0] == 'x'){
                ans[1] = 'S';
                ans[s.size()-1] = 'W';
            }
    return solve_common();
    
}

bool solve_2(void){
    ans[0] = 'S';
    if(s[0] == 'o'){
                ans[1] = 'W';
                ans[s.size()-1] = 'W';
            }
            if(s[0] == 'x'){
                ans[1] = 'W';
                ans[s.size()-1] = 'S';
            }

    return solve_common();
}

bool solve_3(void){
            ans[0] = 'W';
            if(s[0] == 'o'){
                ans[1] = 'S';
                ans[s.size()-1] = 'W';
            }
            if(s[0] == 'x'){
                ans[1] = 'W';
                ans[s.size()-1] = 'W';
            }
    return solve_common();
}

bool solve_4(void){
            ans[0] = 'W';
            if(s[0] == 'o'){
                ans[1] = 'W';
                ans[s.size()-1] = 'S';
            }
            if(s[0] == 'x'){
                ans[1] = 'S';
                ans[s.size()-1] = 'S';
            }
    return solve_common();
}

int main(void){
    ll n;
    cin >> n;
    cin >> s;

    bool bad_ans = false ;

    bad_ans = solve_1();
    if(bad_ans){
        bad_ans = solve_2(); 
    }
    if(bad_ans){
        bad_ans = solve_3();
    }
    if(bad_ans){
        bad_ans = solve_4();
    }
    
    if(bad_ans){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}