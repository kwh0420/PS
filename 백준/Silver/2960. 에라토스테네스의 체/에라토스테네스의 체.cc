#include<bits/stdc++.h>
using namespace std;
int N,K;
vector<bool> state(1000001, true);
int main() {
    cin>>N>>K;
    int cnt=0;
    for(int i=2;i<=N;i++) {
        if (!state[i]){continue;}
        cnt++;
        if (cnt==K){cout << i;return 0;}

        for (int j=i*i;j<=N;j+=i) {
            if (!state[j]){continue;}
                cnt++;
                state[j]=0;
                if (cnt==K){cout << j;return 0;}
        }
    }
}