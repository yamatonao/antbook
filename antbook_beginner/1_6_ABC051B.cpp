#include <iostream>

using namespace std;

int main(void){
    int K=0;
    int S=0;
    int ans =0;

    cin >> K;
    cin >> S;

    for(int x=0; x<=K; x++){
        for(int y=0; y<=K; y++){

            if( S-(x+y) <= K && S-(x+y) >= 0){
//                cout << x << " " << y << " " << S-(x+y) << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}