#include <bits/stdc++.h>
using namespace std;
long long int arr[100002];
long long int has_table[100002];
long long int n,m;
int main() {
    cin >> n ;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long int i=0; i<100002; i++) {
        has_table[i] = -1;//해시테이블 -1로 초기화해주지 않으면 안됨
    }
    long long int st=0;
    long long int en=0;
    long long int count=0;
    while (en<n){
        if (has_table[arr[en]]>=st) {//만약 범위 안에 중복수가 들어있을경우
            st=has_table[arr[en]]+1; // 범위를 중복수 +1로 바꿈
        }
        has_table[arr[en]]=en; 
        count+=en-st+1; //count 계산, right-left+1;
        en++;
    }
    cout << count;

}
