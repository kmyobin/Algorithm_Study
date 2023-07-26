#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int cnt[1101];
int main(void) {
    int n;
    cin >> n;
    int x;
    cin >> x;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int j = 1; j<=x;j++){
        if(cnt[1+j] == 0|| cnt[1+j] > cnt[1]+1 ){
            cnt[1+j]=cnt[1]+1;
        }
    }
    for(int i=2;i<=n;i++){
        int temp;
        cin>>temp;
        for(int j = 1; j<=temp;j++){
            if(cnt[i]!=0){
                if(cnt[i+j] == 0|| cnt[i+j] > cnt[i]+1 ){
                    cnt[i+j]=cnt[i]+1;
                }
            }
        }

    }
    if(cnt[n]==0){
        cout<<-1;
    }
    else{
        cout<<cnt[n];
    }
    return 0;
}

