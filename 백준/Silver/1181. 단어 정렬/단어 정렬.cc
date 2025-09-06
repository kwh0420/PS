#include <bits/stdc++.h>
using namespace std;
long long int n;

class comp {
    ;

public :
    bool operator()(string a, string b) {
        if (a.length() > b.length()) {
            return 1;
        } else if (a.length() < b.length()) {
            return 0;
        } else {
            return a >= b;
        }
    }
};

priority_queue<string, vector<string>, comp> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (long long int i = 0; i < n; i++) {
        string s;
        cin >> s;
        q.push(s);
    }
    string b=" ";
    for (long long int i = 0; i < n; i++) {
        if (b==q.top()) {
            q.pop();
            continue;
        }
        cout << q.top() << "\n";
        b=q.top();
        q.pop();
    }
}
