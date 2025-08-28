#include <bits/stdc++.h>
using namespace std;
int N;
int arr[500000];
int M;
int result[10000002];
int st,en;
int upper_index(int x) {
    while (st<en) {
        int mid=(st+en)/2;
        if (arr[mid]==x) {
            st=mid+1;
        }
        else if (arr[mid]>x) {
            en=mid;
        }
        else {
            st=mid+1;
        }
    }
    return st;
}
int lower_index(int x) {
    while (st<en) {
        int mid=(st+en)/2;
        if (arr[mid]==x) {
            en=mid;
        }
        else if (arr[mid]>x) {
            en=mid;
        }
        else {
            st=mid+1;
        }
    }
    return st;
}
int main() {
    cin >>N;
    for (int i = 0; i < N; i++) {
        cin >>arr[i];
    }
    cin >>M;
    for (int i = 0; i < M; i++) {
        cin >>result[i];
    }
    sort(arr,arr+N);
    for (int i = 0; i < M;i++) {
        st=0;
        en=N;

        int a=upper_index(result[i]);
        st=0;
        en=N;
        int b=lower_index(result[i]);
        cout << a-b<< " ";
    }
}