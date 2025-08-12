#include <bits/stdc++.h>
using namespace std;
int arr[4][8];
int rotate_index[4];
void rotate(int top,int mode) {
        int temp[8]={};
        for (int i=0;i<8; i++) {
            temp[(i+mode+8)%8]=arr[top][i];
        }
        for (int i=0;i<8;i++) {
            arr[top][i]=temp[i];
        }
}
int check (int index, int dir) {
    if (dir==1) {
            if (arr[index][1]!=arr[index+1][5]) {
                return 1;
            }
    }
    else if (dir==-1) {
            if (arr[index][5]!=arr[index-1][1]) {
                return 1;
            }
    }
    return 0;
}
int main() {
    for (int i=0;i<4;i++) {
        string s;
        cin>>s;
        for (int j=0;j<8;j++) {
            arr[i][j]=s[j]-'0';
        }
    }
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int n1,n2;
        cin>>n1>>n2;
        n1--;
        int dirs[4]={0};
        dirs[n1]=n2;
        int idx=n1;
        while (idx<3 && arr[idx][2] != arr[idx+1][6]) {
            dirs[idx+1]=dirs[idx]*(-1);
            idx++;
        }
        idx=n1;
        while (idx>0 && arr[idx][6] != arr[idx-1][2]) {
            dirs[idx-1]=dirs[idx]*(-1);
            idx--;
        }
        for (int i=0; i<4; i++) {
            rotate(i,dirs[i]);
        }

    }
    cout << arr[0][0] + arr[1][0]*2 + arr[2][0]*4 + arr[3][0]*8;
}