#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> s;
vector<pair<string,int>> v;
class comp {
    public:
    bool operator() (const pair<string,int>& p1, const pair<string,int>& p2) {
        return p1.second < p2.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin >> N >> K;
    for (int i=0; i<K; i++) {
        string a;
        cin >> a;
        s[a]=i;
    }
    for (auto i : s) {
        v.push_back(i);
    }
    sort(v.begin(), v.end(),comp());
    int en = min(N, (int) v.size());
    for (int i=0; i<en; i++) {
        cout << v[i].first << "\n";
    }

}