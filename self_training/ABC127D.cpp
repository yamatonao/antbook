#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int n;
long long int m;
long long int tmp1;
long long int tmp2;
long long int ans;
vector<long long int> cards;
vector<pair<long long int,long long int> > change_order;



int main(void){
    cin >> n;
    cin >> m;
    for(long long int i=0; i<n; i++){
        cin >> tmp1;
        cards.push_back(tmp1);
    }

    for(long long int i=0; i<m; i++){
        cin >> tmp1;
        cin >> tmp2;
        change_order.push_back( make_pair(tmp1, tmp2) );
    }

    //ソートする
    sort(cards.begin(), cards.end());
    for(int i=0; i<change_order.size(); i++){
        for(int j=0; j<change_order[i].first; j++ ){
            if(cards[j] < change_order[i].second ){
                cards[j]= change_order[i].second;
            }else{
                break;
            }
        }
        sort(cards.begin(), cards.end());
    }

    for(long long int i=0; i<n; i++){
        ans += cards[i];
    }
    cout << ans << endl;

    return 0;
}