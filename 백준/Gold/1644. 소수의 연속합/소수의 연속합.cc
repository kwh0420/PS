#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<bool> state(4000009,1);
long long int n,m;
int main() {
    cin >> n ;

    for (long long int i = 2; i <= n; i++) {
        if (!state[i]) {continue;}
        for (long long int j=i*i; j<=n; j+=i) {
            state[j]=0;
        }
    }
    for (long long int i = 2; i <= n; i++) {
        if (state[i]) {
            prime.push_back(i);
        }
    }
    long long int st=0;
    long long int en=0;
    long long int sumval=0;
    long long int cnt=0;
    prime.push_back(0);
    while (en<=prime.size()) {
        if (sumval<n) {
            sumval+=prime[en];
            en++;
        }
        else if (sumval>n) {
            sumval-=prime[st];
            st++;
        }
        else {
            cnt++;
            sumval-=prime[st];
            st++;
        }
    }
    cout << cnt;
}