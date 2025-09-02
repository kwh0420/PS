#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> arr[200004];
vector<long long int>result;
long long int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N;
    cin >> N;
    for (long long int i = 0; i < N; i++) {
        cin >> arr[i].first;
        arr[i].second=i;
    }
    long long int total_sum=0;
    long long int before_sum=0;
    long long int before_minval=0;
    long long int minval=0;
    int index=0;
    sort(arr,arr+N,greater<pair<long long int,long long int>>());
    for (int i=0; i<N; i++) {
        total_sum+=arr[i].first;
        int idx=i;
        minval=arr[i].first;
        while (arr[idx].first==arr[idx+1].first) {
            total_sum+=arr[idx].first;
            idx++;

        }
        i=idx;

        if (total_sum+minval>=before_sum + before_minval ) {
            before_sum=total_sum;
            before_minval=minval;
            index=idx;
        }
    }



    cout << index+1 <<'\n';
    for (int i=0; i<=index;i++) {
        cout << arr[i].second+1 << " ";
    }
}
