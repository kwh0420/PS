#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100002];
int binary_search(int st, int en, int target) {
    while (st<=en) {
        int mid=(st+en)/2;
        if (arr[mid]==target) {
            cout<<1 <<"\n";
            return 1;
        }
        else if (arr[mid]>target) {
            en=mid-1;
        }
        else {
            st=mid+1;
        }
    }
    cout <<0<<"\n";
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>N;
    for (int i=0; i<N; i++) {
        cin >>arr[i];
    }
    sort(arr,arr+N);
    int M;
    cin >>M;
    for (int i=0; i<M; i++) {
        int target;
        cin >>target;
        int st=0;
        int en=N-1;
        binary_search(st,en,target);
    }

}