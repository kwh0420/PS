#include <bits/stdc++.h>
using namespace std;
vector<long long int> plusarr;
vector<long long int> minusarr;
long long int valueofzero;

 int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        long long int a;
        cin >> a;
        if (a>0) {
            plusarr.push_back(a);
        }
        else if (a<0) {
            minusarr.push_back(a);
        }
        else {
            valueofzero=1;
        }
    }
    long long int sum=0;
    sort(plusarr.begin(), plusarr.end(), greater<long long int>());
    sort(minusarr.begin(), minusarr.end());

    long long int idx=0;
    while (idx<plusarr.size()) {
        if (idx==plusarr.size()-1) {
            sum+=plusarr[idx];
            break;
        }
        else if (plusarr[idx]==1 || plusarr[idx+1]==1) { //1인경우 곱하면 손해인걸 고려해주지 못함
            sum+=plusarr[idx];
            idx+=1;
        }
        else {
            sum+=plusarr[idx]*plusarr[idx+1];
            idx+=2;
        }
    }
     idx=0;
    while (idx<minusarr.size()) {
        if (idx==minusarr.size()-1) {
            if (valueofzero==1) {
                break;
            }
            sum+=minusarr[idx];
        }
        else {
            sum+=minusarr[idx]*minusarr[idx+1];
        }
        idx+=2;
    }
     cout << sum;

}
