#include <bits/stdc++.h>
using namespace std;
int nxt[240];
int loc[4]={0,0,0,0};
int dice[10];
int mapping[33];
int maxval=0;
int cursum=0;
int go(int num,int K) {
    int curloc=loc[num];
    if (curloc==5) {
        curloc=21;
        K--;
    }
    else if (curloc==10 ) {
        curloc=24;
        K--;
    }
    else if (curloc==15) {
        curloc=26;
        K--;
    }
    for (int i=K; i>0; i--) {
        if (curloc==32)break;
        curloc=nxt[curloc];
    }

    for (int i=0; i<4; i++) {
        if (i==num)continue;
        if (loc[i]==curloc && loc[i]!=32){return 0;}
    }
    loc[num]=curloc;
    cursum+=mapping[curloc];
    return 1;

}
void backtracking(int n) {
    //  cout << "cur step : " << n;
    //  cout << endl;
    //  for (int i=0; i<4; i++) {
    //      cout << loc[i] << " ";
    //  }
    //  cout << endl;
    // cout << "cur score : " << cursum;
    if (n==10){maxval=max(maxval,cursum);return;}
    for (int i=0;i<4;i++) {
        if (loc[i]==32)continue;
        int p=loc[i];
       if (go(i,dice[n])) {
           backtracking(n+1);
           cursum-=mapping[loc[i]];
           loc[i]=p;
       }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i=0; i<=19; i++) {
        nxt[i]=(i+1);
        mapping[i]=i*2;
    }
    mapping[20]=40;
    mapping[21]=13;
    mapping[22]=16;
    mapping[23]=19;
    mapping[24]=22;
    mapping[25]=24;
    mapping[26]=28;
    mapping[27]=27;
    mapping[28]=26;
    mapping[29]=25;
    mapping[30]=30;
    mapping[31]=35;
    nxt[20]=32;
    nxt[21]=22;
    nxt[22]=23;
    nxt[24]=25;
    nxt[26]=27;
    nxt[27]=28;
    nxt[23]=29;
    nxt[25]=29;
    nxt[28]=29;
    nxt[29]=30;
    nxt[30]=31;
    nxt[31]=20;
    for (int i=0; i<10; i++) {
        cin >> dice[i];
    }
    backtracking(0);
    cout << maxval;
}