#include <bits/stdc++.h>
using namespace std;
int arr[16];
int main() {
    int n;
    long long int coin=0;
    long long int money=0;
    cin>>n >>money;
    for(int i=1;i<=n;i++){cin >> arr[i];}
    for (int i=1;i<=n;i++) {
        if (arr[i]<arr[i+1]){coin += money/arr[i];money%=arr[i];}
        else if (arr[i]>=arr[i+1]){money+= coin *arr[i]; coin=0;}
    }
    cout << money;
}