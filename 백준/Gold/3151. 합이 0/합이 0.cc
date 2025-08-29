#include <bits/stdc++.h>
using namespace std;
long long int N;
vector <long long int>arr;
long long int cnt=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (long  long int i = 0; i < N; i++) {
        long long int k;
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());
    for (long int i = 0; i < N; i++) {
        for (long long int j = i+1; j < N; j++) {
            int a=i;
            int b=j;
            int target=-(arr[a]+arr[b]);
            auto st=arr.begin()+b+1;
            auto en=arr.end();
            if (en>=st) {
                cnt+=upper_bound(st, en,target)-lower_bound(st,en,target);
            }
        }
    }
    cout<< cnt;
}