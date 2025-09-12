#include <bits/stdc++.h>
using namespace std;
vector<string> son[1002];
int indegree[1002];
map<int, string>i2s;
map<string,int>s2i;
vector<string> v[1002];
set<string> root;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        i2s[i]=s;
        s2i[s]=i;
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++) {
        string s1,s2;
        cin>>s1>>s2;
        int a1 = s2i[s1];
        int a2 = s2i[s2];
        v[a2].push_back(i2s[a1]);
        indegree[a1]++;
    }
    queue<int> q;
    for (int i=0;i<n;i++) {
        if (indegree[i] == 0) {
            root.insert(i2s[i]);
            q.push(i);
        }
    }
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for (string j:v[i]) {
            indegree[s2i[j]]--;
            if (indegree[s2i[j]] == 0) {
                q.push(s2i[j]);
                son[i].push_back(j);
            }
        }
    }
    cout << root.size() << "\n";
    for (auto i : root) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : s2i) {
        string s = i.first;
        cout << s << " ";
        cout << son[s2i[s]].size() << " ";
        sort(son[s2i[s]].begin(),son[s2i[s]].end());
        for (auto k : son[s2i[s]]) {
            cout << k << " ";
        }
        cout << "\n";
    }


}