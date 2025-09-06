#include <bits/stdc++.h>
using namespace std;
long long int T,N,M;
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>T;
    while(T--) {
        cin >>N;
        cin >>M;
        vector<long long int> a(N);
        vector<long long int> b(M+1);
        for (long long int i=0; i<N; i++) {
            cin >>a[i];
        }
        for (long long int j=0; j<M; j++) {
            cin >>b[j];
        }
        b[M]=1e18;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long int a1=0;
        long long int b1=0;
        long long int sum=0;
        long long int totalsum=0;
        while (a1<N && b1<=M) {
            while (a[a1]>b[b1]){b1++;sum++;}
            totalsum+=sum;
            a1++;
        }
        cout << totalsum<<"\n";
    }
}
