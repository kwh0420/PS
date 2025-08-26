#include <bits/stdc++.h>
using namespace std;
int arr[2];
string s;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int tmp=0;
    int mode=0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='+' || s[i]=='-') {
            arr[mode]+=tmp;
            tmp=0;
            if (s[i]=='-') {
                mode=1;
            }
        }
        else {
           tmp*=10;
            tmp+=s[i]-'0';

        }
    }
    arr[mode]+=tmp;
    cout << arr[0]-arr[1];

}