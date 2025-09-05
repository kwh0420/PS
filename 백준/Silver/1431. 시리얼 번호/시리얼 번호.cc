#include <bits/stdc++.h>
using namespace std;
vector<string>v;
int comp(string& a, string& b) {
    if (a.size() <b.size()) {
        return 1;
    }
    else if (a.size() > b.size()) {
        return 0;
    }
    else {
        int n=0;
        int m=0;
        for (int i=0; i<a.size(); i++) {
            if ('0'<=a[i]&&a[i]<='9') {
                n+=a[i]-'0';
            }
            if ('0'<=b[i]&&b[i]<='9') {
                m+=b[i]-'0';
            }
        }
        if (n<m) {
            return 1;
        }
        else if (n>m) {
            return 0;
        }
        else {
            if (a<b) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    for (int i=0; i<k; i++) {
        string a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), comp);
    for (int i=0; i<v.size(); i++) {
        cout<<v[i]<<"\n";
    }
}