#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int arr[100005];
int main() {
    cin>>n>>m;
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    long long int start=0,end=0;
    long long int minval = 1e18;
    long long int k=0;

    while(end<=n) { //END는 현재 요소의 +1에 존재한다. 따라서, END==N일때도 범위를 포함해야한다.
        if (k<m) {
            k+=arr[end];
            end++;
        }
        else if (k>=m) {
            minval = min(minval,end-start);
            k-=arr[start++];
        }
    }
    cout << ((minval==1e18)?0:minval);

}
