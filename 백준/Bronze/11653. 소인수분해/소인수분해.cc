#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<bool>prime(1000001,1);

int main() {
    int M,N;
    cin>>N;
    prime[1]=0;
    for (int i=2; i*i<=N; i++) {
        while (N%i==0) {
            cout << i << "\n";
            N=N/i;
        }
    }
    if (N!=1) {
        cout << N << "\n";
    }


}