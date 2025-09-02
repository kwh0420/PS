#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<bool>prime(1000001,1);

int main() {
    int M,N;
    cin>>M>>N;
    prime[1]=0;
    for (int i=2; i*i<=N; i++) {
        if (!prime[i]) {continue;}

        for (int j=i*i; j<=N; j+=i) {
            prime[j]=false;
        }
    }
    for (int i=M; i<=N; i++) {
        if (prime[i]) { cout << i << "\n"; }
    }

}