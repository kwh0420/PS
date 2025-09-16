#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >>n;
    long long int sum=2;
    for (int i=1; i<n; i++) {
        if (i%2==1){continue;}
        sum=(sum*2)%16769023;
    }
    cout<<sum;
}