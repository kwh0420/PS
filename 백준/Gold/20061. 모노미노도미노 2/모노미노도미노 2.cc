#include <bits/stdc++.h>
using namespace std;
int N;
int totalscore=0;
int totalblock=0;
int arr[3][6][4];
void del(int row,int mode) {
    for (int i=row; i>=1; i--) {
        for (int j=0; j<4; j++) {
            arr[mode][i][j] = arr[mode][i-1][j];
        }
    }
    for (int j=0; j<4; j++) {
        arr[mode][0][j]=0;
    }
}
void del2(int numofdel,int mode) {
    for (int i=5; i>=2; i--) {
        for (int j=0; j<4; j++) {
            arr[mode][i][j] = arr[mode][i-numofdel][j];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            arr[mode][i][j] = 0;
        }
    }
}
void printx(int mode) {
        cout << "mode : " << mode << endl;
        for (int i=0; i<6; i++) {
            for (int j=0; j<4; j++) {
                cout << arr[mode][i][j] << " ";
            }
            cout << endl;
        }
    cout << "---------------\n";

}
void func(int mode,int t, int x, int y) {
    int row1=-1, col1=-1, row2=-1, col2=-1;
    if (mode==1) {
        if (t==1) {
            row1=0;
            col1=y;
        }
        else if (t==2) {
            row1=0;
            col1=y;
            row2=0;
            col2=y+1;
        }
        else if (t==3) {
            row1=1;
            col1=y;
            row2=0;
            col2=y;
        }
    }
    if (mode==2) {
        if (t==1) {
            row1=0;
            col1=x;
        }
        else if (t==2) {
            row1=1;
            col1=x;
            row2=0;
            col2=x;

        }
        else if (t==3) {
            row1=0;
            col1=x+1;
            row2=0;
            col2=x;
        }
    }

    if (t==1) {
        while (row1<6) {
            if (arr[mode][row1][col1] )break;
            row1++;
        }
        arr[mode][row1-1][col1] = 1;
    }
    else if (t==2||t==3) {
        while (row1<6 ){
            if (arr[mode][row1][col1] || (arr[mode][row2][col2]))break;
            row1++;row2++;
        }
        arr[mode][row1-1][col1]=1;
        arr[mode][row2-1][col2]=1;
    }
    int currow=5;
    int temp[6][4]={0};
    for (int i=5; i>=0;i--) {
        for (int j=0; j<4; j++) {
            if (arr[mode][i][j]==0) {
                for (int k=0; k<4; k++) {
                    temp[currow][k] = arr[mode][i][k];
                }
                currow--;
                break;
            }
            if (j==3) {
                totalscore++;
            }
        }
    }
    swap(temp,arr[mode]);


    int numofdel=0;
        for (int i=0; i<2; i++) {
            for (int j=0; j<4; j++) {
                if (arr[mode][i][j]){numofdel++;break;}
            }
        }
    del2(numofdel,mode);

}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int  t,x,y;
        cin >> t >> x >> y;
        func(1,t,x,y);
        func(2,t,x,y);
    }
    cout << totalscore << "\n";

    for (int i = 0; i < 6; i++) {
        for (int j=0; j<4; j++) {
            totalblock+=arr[1][i][j];
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j=0; j<4; j++) {
            totalblock+=arr[2][i][j];
        }
    }
    cout << totalblock;
}
