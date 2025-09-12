#include <bits/stdc++.h>
using namespace std;
int par[100002];
vector<int> v[100002];
map<char,pair<char,char>>m;
void dfs1(char cur) {
    if (cur=='.'){return;}
    char lc = m[cur].first;
    char rc = m[cur].second;
    cout << cur;
    dfs1(lc);
    dfs1(rc);
}
void dfs2(char cur) {
    if (cur=='.'){return;}

    char lc = m[cur].first;
    char rc = m[cur].second;
    dfs2(lc);
    cout << cur;
    dfs2(rc);
}void dfs3(char cur) {
    if (cur=='.'){return;}

    char lc = m[cur].first;
    char rc = m[cur].second;
    dfs3(lc);
    dfs3(rc);
    cout << cur;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a,b,c;
        cin >> a >> b >> c;
        m[a] = make_pair(b,c);
    }
    dfs1('A');
    cout <<'\n';
    dfs2('A');
    cout <<'\n';

    dfs3('A');
}
