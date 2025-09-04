#include <bits/stdc++.h>
using namespace std;
long long  int N,K;
long long int arr[1000002];
queue<long long  int> q;
 int main() {
    cin>>N>>K;
    for(long long int i=0;i<N;i++)
        cin >> arr[i];
    long long int st=0;
    long long int en=0;
    long long int least=0;
    long long int cnt=0;
    long long int length=0;
    while (en<N) {
        if (arr[en]%2==1) {
            q.push(en);
            if (length<=K-1) {
                length++;
            }
            else{
                st=q.front()+1;
                q.pop();
            }
        }
        cnt = max(cnt,en-st+1-length);
        en++;
    }
    cout << cnt;
}