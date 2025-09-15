#include <bits/stdc++.h>
using namespace std;
string a1, a2;
char result[2];
int dp(int pointer1,int pointer2, int idx) {
    int result1=0;
    int result2=0;
    if (pointer1 <0 && pointer2 < 0) {return 1;}
    if (pointer1>=0&&pointer2>=0&&a1[pointer1] == a2[pointer2]) {
        result1=dp(pointer1-1,pointer2-1,idx);
    }
    if (idx>=0&&a2[pointer2] == result[idx]) {
        result2=dp(pointer1,pointer2-1,idx-1);
    }
    return max(result1,result2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin >> a1 >> a2;
    int idx1, idx2;
    cin >> idx1 >> idx2;
    if (a1.compare(a2)==0){cout << "YES"; return 0;}

    result[0] = a1[idx1];
    result[1] = a1[idx2];
    a1.erase(idx2, 1);
    a1.erase(idx1, 1);
    int result=dp(n-2,n,1);
    if (result)
    cout << "YES";
    else
        cout << "NO";
}
