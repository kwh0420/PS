#include <bits/stdc++.h>
using namespace std;
int main() {
    int E,S,M;
    cin>>E>>S>>M;
    while (1) {
        if ((E%28==0&&S==28)||E%28==S) {
            break;
        }
        E+=15;
    }
    int sumcnt=lcm(15,28);
    while (1) {
        if ((E%19==0&&M==19)||E%19==M) {
            break;
        }
        E+=sumcnt;
    }
    cout << E;
}