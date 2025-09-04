#include <bits/stdc++.h>
using namespace std;
long long int arr[100002];
long long int has_table[100002];
long long int n,m;
int main() {
    cin >> n ;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long int i=0; i<100002; i++) {
        has_table[i] = -1;
    }
    long long int st=0;
    long long int en=0;
    long long int count=0;
    while (en<n){
        if (has_table[arr[en]]>=st) {
            st=has_table[arr[en]]+1;
        }
        has_table[arr[en]]=en;
        count+=en-st+1;
        en++;
    }
    cout << count;
}