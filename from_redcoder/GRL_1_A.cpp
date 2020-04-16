// RUNTIME ERROR 何故か

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

int main(){
    typedef pair<ll, ll> ToEdge; // to cost
    typedef pair<ll, ll> P; // shortest Distance / Node
    ll v;
    ll e;
    ll r;
    cin >> v >> e >> r;

    ll all_cost[v];
    REP(i,v){
        all_cost[i] = INF;
    }
    all_cost[r] =0;

    vector<vector< ToEdge > > graph(v);    // 要注目 (n)はベクターの要素数
    priority_queue<P, vector<P>, greater<P> > pque;

    REP(i,e){
        ll s;
        ll t;
        ll d;
        cin >> s >> t >> d;
        graph[s].push_back( make_pair(t , d ));
    }

    REP(i,v){
        sort( ALL(graph[i]) );
    }

    pque.push( make_pair(all_cost[r],r) );

    while(!pque.empty()){
        P p_tmp = pque.top();
        pque.pop();

        ll now_node = p_tmp.second;

        if(all_cost[now_node] < p_tmp.first){continue;}

        for(ll i=0; i<graph[now_node].size(); i++){
            ToEdge next_edge = graph[now_node][i];
            if( all_cost[next_edge.first] > (all_cost[now_node]+ next_edge.second) ){
                all_cost[next_edge.first] = (all_cost[now_node]+ next_edge.second);
                                        // 次の頂点までの最短コスト    次の頂点
                pque.push(make_pair( all_cost[next_edge.first], next_edge.first));
            }
        }
    }


    REP(i,v){
        if( all_cost[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << all_cost[i] << endl;
        }
    }
    return 0;
}
