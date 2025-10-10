#include <bits/stdc++.h>
using namespace std;
int cnt;
int visited[14];
int arr[5][5];
int a,b,c,d,e,f,g,h,i,j,k,l,m;
void dfs(int depth) {
    // for (int i=0; i<5; i++) {
    //     for (int j=0; j<5; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout<<"\n";
    // }
    // for (int i=1; i<14; i++) {
    //     cout <<visited[i]<<" ";
    // // }
    // cout <<"\n";
    // cout << "---------------------\n";
    if (depth ==1) {//l,m 확정
        for (int num=1; num<=13; num++) {
            l=num;
            m=arr[4][0]-num;

            if (l==m || m<=0 || m>13) continue;
            arr[4][1]=l;
            arr[4][2]=m;
            visited[l]=1;
            visited[m]=1;
            dfs(2);
            arr[4][1]=0;
            arr[4][2]=0;
            visited[l]=0;
            visited[m]=0;
        }
    }
    if (depth==2) {//d,h 확정
        for (int num=1; num<=13; num++) {
            d=num;
            h=arr[0][4]-num;
            if (d==h) {continue;}
            if (h<=0||h>13||visited[d] || visited[h] ){continue;}
            arr[1][4]=d;
            arr[2][4]=h;
            visited[d]=1;
            visited[h]=1;
            dfs(3);
            arr[1][4]=0;
            arr[2][4]=0;
            visited[d]=0;
            visited[h]=0;
        }
    }
    if (depth==3) { // a확정
        for (int num=1; num<=13; num++) {
            a=num;
            if (visited[a]){continue;}
            arr[1][1]=a;

            visited[a]=1;
            dfs(4);
            arr[1][1]=0;
            visited[a]=0;

        }
    }
    if (depth==4) { // b,c 확정
        for (int num=1; num<=13; num++) {
            b=num;
            c=arr[1][0]-b-d-a;
            if (b==c|| c<=0|| c>13||visited[b] || visited[c] ){continue;}
            arr[1][2]=b;
            arr[1][3]=c;
            visited[b]=1;
            visited[c]=1;
            // cout << "b : " << b << "c : " << c << endl;
            dfs(5);
            arr[1][2]=0;
            arr[1][3]=0;
            visited[b]=0;
            visited[c]=0;
            // cout << "b : " << b << "c : " << c << endl;

        }
    }
    if (depth==5) { // e확정
        for (int num=1; num<=13; num++) {
            e=num;
            if (visited[e]){continue;}
            arr[2][1]=e;

            visited[e]=1;
            dfs(6);
            arr[2][1]=0;
            visited[e]=0;

        }
    }
    if (depth==6) { // f,g 확정
        for (int num=1; num<=13; num++) {
            f=num;
            g=arr[2][0]-e-f-h;
            if (f==g||g<=0 ||g>13||visited[f] || visited[g] ){continue;}
            arr[2][2]=f;
            arr[2][3]=g;
            visited[f]=1;
            visited[g]=1;
            dfs(7);
            arr[2][2]=0;
            arr[2][3]=0;
            visited[f]=0;
            visited[g]=0;
        }
    }
    if (depth==7) { // i,j,k확정, cnt++
        i=arr[0][1]-a-e-l;
        j=arr[0][2]-b-f-m;
        k=arr[0][3]-c-g;
        if (i<=0 || j<=0 || k<=0){return ;}
        if (13<i || 13<j || 13<k){return ;}
        if (i==j || j==k || k==i) {return ;}
        if (k!=arr[3][0]-i-j || visited[i] || visited[j] || visited[k]){return;}
        cnt++;
        arr[3][1]=i;
        arr[3][2]=j;
        arr[3][3]=k;
        //  for (int i=0; i<5; i++) {
        //      for (int j=0; j<5; j++) {
        //          cout << arr[i][j] << " ";
        //      }
        //      cout<<"\n";
        //  }
        // cout <<"-------------\n";
        arr[3][1]=0;
        arr[3][2]=0;
        arr[3][3]=0;
        return ;
    }
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < 5; i++) {cin >> arr[0][i];}
    for (int i = 1; i < 5; i++) {cin >> arr[i][0];}
    // for (int i=0; i<5; i++) {
    //     for (int j=0; j<5; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout<<"\n";
    // }
    dfs(1);
    cout << cnt;
}
