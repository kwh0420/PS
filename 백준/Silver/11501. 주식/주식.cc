#include <bits/stdc++.h>
using namespace std;
long long int arr[2];
string s;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int i=0; i<t; i++) {
        int n;
        cin>>n;
        vector<long long int> arr(n,0);
        for (int j=0; j<n; j++) {
            cin>>arr[j];
        }
        long long int maxval=0;
        long long int sum=0;
        for (int j=n-1; j>=0; j--) {
            maxval=max(maxval, arr[j]);
            if (maxval>arr[j]) {
                sum+=maxval-arr[j];
            }
        }
        cout<<sum<<"\n";
    }

}