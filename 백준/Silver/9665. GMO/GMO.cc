#include <bits/stdc++.h>
using namespace std;
string a;
string b;
int dp[10000];
map<char,int>m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>a;
    cin>>b;
    int A,C,G,T;
    cin >> A >> C >> G >> T;
    m['A'] = A;
    m['C'] = C;
    m['G'] = G;
    m['T'] = T;
    int i;
    i=0;
    int maxval=0;
    int totalsum=0;
    for (int i=0; i<b.length();i++) {
        totalsum+=m[b[i]];
    }
    while (i<a.length()) {
        int sum=0;
        int ori=i;
        for (int j=0; j<b.length(); j++) {
            if (a[i] == b[j]) {
                sum+=m[a[i]];

                i++;
            }
        }
        i=ori+1;
        maxval = max(maxval,sum);
    }
    cout << totalsum-maxval ;
}