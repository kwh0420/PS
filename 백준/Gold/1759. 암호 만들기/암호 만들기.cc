#include <bits/stdc++.h>
using namespace std;
char s[50];
int L, T;
string result;
void go(int depth,int cnt) {
    if (cnt == L) {
        int mocnt=0;
        int zacnt=0;
        for (auto i : result) {
            if (i=='a'||i=='e'||i=='i'||i=='o'||i=='u') {mocnt++;}
            else {zacnt++;}
        }
        if (mocnt>=1 && zacnt >=2)
            cout << result << "\n";
        return;
    }
    for (int i=depth+1; i<T; i++) {
        result.push_back(s[i]);
        go(i,cnt+1);
        result.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> T;
    for (int i = 0; i < T; i++) {
        cin >> s[i];
    }
    sort(s, s + T);
    go(-1,0);

}
