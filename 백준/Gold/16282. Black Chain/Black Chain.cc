#include <bits/stdc++.h>
using namespace std;
long long int p2[102];
long long int arr[102];
int main() {
    p2[0]=1;
    p2[1]=2;
    arr[1]=1;
    for (int i = 2; i <= 100; i++) {
        p2[i] = p2[i - 1]*2;
    }
    for (int i = 2; i <= 100; i++) {
        arr[i]= i*p2[i]-1;
    }
    long long int target;
    cin>>target;
    long long int cnt=0;
    while (target>arr[cnt+1]){cnt++;}
    cout << cnt;
}