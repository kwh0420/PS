#include <bits/stdc++.h>
using namespace std;
int M,N;
int arr[1000002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>M>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    int lo=1;
    int hi=arr[N-1];
    int sum=0;
    for(int i=0 ;i<N;i++) {
        sum+=arr[i];
    }
    if (sum<M) {
        cout << 0;
        return 0;
    }
    sum=0;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        sum=0;
        for (int i=0;i<N;i++) {
            sum+=arr[i]/mid;
        }
        if (sum==M) {
            lo=mid;
        }
        else if (sum>M) {
            lo=mid;
        }
        else {
            hi=mid-1;
        }
    }
    cout<<hi;
}