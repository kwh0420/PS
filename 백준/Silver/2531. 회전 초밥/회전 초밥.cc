#include <bits/stdc++.h>
using namespace std;
int arr[30001];
int vis[3002];
int N,d,k,c;
int main() {
    cin>>N>>d>>k>>c;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    int cnt=0;
    int st=0;
    int en = (st+k-1)%N;
    vis[c]++;
    cnt++;
    for (int i=0;i<k; i++) {
        if (vis[arr[i%N]]==0) {
            cnt++;
        }
        vis[arr[i%N]]++;
    }
    int maxval=cnt;

    while (st<N){
        vis[arr[st%N]]--;
        if (vis[arr[st%N]]==0) {
            cnt--;
        }
        st++;
        int new_index = arr[(en+1)%N];
        if(vis[new_index]==0) {
            cnt++;
        }
        maxval=max(maxval,cnt);
        vis[new_index]++;
        en=(en+1)%N;
    }
    cout << maxval;
}