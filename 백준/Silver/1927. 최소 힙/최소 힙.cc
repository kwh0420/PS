#include <bits/stdc++.h>
using namespace std;
int arr[200002];
int sz=0;
void add (int a) {
    arr[++sz] = a;
    int cur=sz;
    while (cur!=1) {
        int par = cur/2;
        if (arr[par] > arr[cur]) {
            swap(arr[par], arr[cur]);
            cur = par;
        }
        else {
            break;
        }
    }
}
void del () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    if (sz==0) {
        cout <<0 <<"\n";
        return;
    }
    cout << arr[1]<<"\n";
    arr[1]=arr[sz];
    sz--;
    int cur=1;
    while (cur*2<=sz) {
        int left = cur*2;
        int right = cur*2+1;
        int small= left;
        if (right<=sz && arr[left]>arr[right]) {
            small = right;
        }
        if (arr[small]>=arr[cur]) {
            break;
        }
        swap(arr[cur], arr[small]);
        cur = small;
    }
    return;
}

int main() {

    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        if (k==0) {
            del();
        }
        else {
            add(k);
        }
    }
}