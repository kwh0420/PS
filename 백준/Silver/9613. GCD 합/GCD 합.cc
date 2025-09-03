#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++) {
        long long int k;
        cin>>k;
        vector<long long int> v;
        for(long long int j=0;j<k;j++) {
            long long int a;
            cin>>a;
            v.push_back(a);
        }
        long long int sum=0;
        for(long long int j=0;j<k;j++) {
            for(long long int p=j+1;p<k;p++) {
                sum+=gcd(v[j],v[p]);
            }
        }
        cout << sum <<"\n";
    }
}