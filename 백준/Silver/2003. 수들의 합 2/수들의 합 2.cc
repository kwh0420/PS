#include <bits/stdc++.h>
using namespace std;
long long int arr[10002];
long long int n,m;
int main() {
    cin >> n >> m;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int st=0;
    long long int en=0;
    long long int sum=0;
    long long int cnt=0;
    while (en<=n){
        if (sum<m) {
            sum+=arr[en];
            en++;
        }
        else if (sum>m) {
            sum-=arr[st];
            st++;
        }
        else {
            cnt++;
            sum-=arr[st];
            st++;

        }
    }
    cout << cnt;
}