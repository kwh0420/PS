#include <bits/stdc++.h>
using namespace std;
long long int n,m;
int arr[10000];
int idx=1;
int main() {
    for (int i = 1; i < 100; i++) {
        int cnt=i;
        while (cnt>0) {
            arr[idx++]=i;
            cnt--;
        }
    }
    int a,b;
    cin>>a>>b;
    int sum=0;
    for (int i = a; i <= b; i++) {
        sum+=arr[i];
    }
    cout<<sum<<endl;
}