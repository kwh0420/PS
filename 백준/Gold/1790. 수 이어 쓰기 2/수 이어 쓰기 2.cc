#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int arr[10000];
long long int idx=1;
long long int func(long long int cnt) {
    long long int a=1;
    for (long long int i=0; i<cnt; i++) {
        a*=10;
    }
    return a;
}
int main() {
    long long int N,K;

    cin>>N>>K;
        long long int totalsum=0;
        long long int cnt=0;
        while (1){
            totalsum+=func(cnt-1)*9*cnt;
            if (totalsum+func(cnt)*9*(cnt+1)>=K){break;}
            cnt++;
        }
        cnt++;
        int num = func(cnt-1)+(K-totalsum-1)/cnt;
        if (num>N) {
            cout << -1;
            return 0;
        }
    cout << to_string(num)[(K-totalsum-1)%(cnt)] << " ";

}