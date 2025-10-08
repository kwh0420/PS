#include <bits/stdc++.h>
using namespace std;
int n;
char inst[4]={'D','S','L','R'};
int func(int a) {
    vector <int> v(4,0);
    for(int i=0;i<4;i++) {
        v[i] = a%10;
        a/=10;
    }
    int q=0;
    for(int i=0;i<4;i++) {
        q += v[(2-i+4)%4];
        if (i!=3)
        q*=10;
    }
    return q;
}
int func2(int a) {
    vector <int> v(4,0);
    for(int i=0;i<4;i++) {
        v[i] = a%10;
        a/=10;
    }
    int q=0;
    for(int i=0;i<4;i++) {
        q += v[(4-i)%4];
        if (i!=3)
        q*=10;
    }
    return q;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        vector<int> v(10002,0);
        int st,en;
        cin >> st >> en;
        queue<int> q;
        q.push(st);
        vector<char>instruction(10002,0);
        vector<int> pre(10002,-1);
        while (!q.empty()) {
            int k = q.front();
            if (k==en) {
                int cur=en;
                string s;
               while (cur!=st) {
                   s.push_back(instruction[cur]);
                   cur = pre[cur];
               }
                reverse(s.begin(),s.end());
                cout << s<<"\n";break;
            }
            q.pop();
            int a=(k*2)%10000;
            int b=(k-1+10000)%10000;
            int c =func(k);
            int d=func2(k);
            vector<int> v2(4,0);

            v2[0]=a;
            v2[1]=b;
            v2[2]=c;
            v2[3]=d;
            for(int i=0;i<4;i++) {
                if (instruction[v2[i]]) {continue;}
                instruction[v2[i]]=inst[i];
                pre[v2[i]]=k;
                q.push(v2[i]);
            }
        }
    }
}