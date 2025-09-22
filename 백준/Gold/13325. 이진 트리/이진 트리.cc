#include <bits/stdc++.h>
using namespace std;
long long int N;
#define ll long long int
ll p2[30];
long long int sumval[10000000];
long long int arr[10000000];

 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p2[0]=1;
    for (long long int i=1; i<30 ;i++) {
        p2[i]=1;
        p2[i]=p2[i-1]*2;
    }

    cin >> N;
    for (long long int i=1; i<=2*(p2[N]-1); i++) {cin >> arr[i];}
    for (long long int j=N+1; j>=0; j--) {
        for (long long int i=p2[j]-1; i<p2[j+1]-1; i+=2) {
            if (sumval[i]>sumval[i+1]){arr[i+1]+=sumval[i]-sumval[i+1];}
            else {arr[i]+=sumval[i+1]-sumval[i];}
            long long int val = max (sumval[i],sumval[i+1]);
            sumval[i]=val;
            sumval[i+1]=val;
            sumval[(i-1)/2]+= val+arr[(i-1)/2];
        }
    }
    long long int ans=0;
    for (long long int i=1; i<=2*(p2[N]-1); i++) {ans+=arr[i];}

    cout << ans;
}