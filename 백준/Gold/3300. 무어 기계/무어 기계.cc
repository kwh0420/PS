#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        string s1;
        cin>>s >> s1;
        int index = s.find('_');
        char k=0;
        int cnt=0;
        for(int i='A';i<='Z';i++) {

            s[index] = i;
            regex pattern(s);

            if (regex_match(s1,pattern)) {k=i;cnt++;}
        }
        if (cnt>1) {cout << "_";}
        else if (cnt==0){cout <<"!";}
        else {cout << k;}
        cout <<"\n";
    }
}