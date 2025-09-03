#include <bits/stdc++.h>
using namespace std;
long long int arr[1000002];
long long int N;
long long int cnt=-1;
long long int target=0;
void go(long long int depth, long long int M) {
    target*=10;
    target+=M;
    if (depth==0) {
        cnt++;
        if (cnt==N) {
            cout <<target;
            exit(0);
        }
    }
    else {
        for (long long int i=0; i<M; i++) {
            go(depth-1,i);
        }
    }
    target/=10;
}
int main() {
    cin>>N;

    for (long long int i=0;i<=9;i++) {
       for (long long int j=0;j<=9;j++) {
           target=0;
           go(i,j);
       }
   }
    cout << -1;
}