#include <bits/stdc++.h> // 1로는 1을 만들수 있다. 1,2,4 로 7이하의 모든 조합을 만들 수 있다. 1,1,3,6,12로는 23이하의 모든 조합을 만들 수 있다. 진법에 대한 이해가 필요한 문제
using namespace std;
long long int p2[102];
long long int arr[102];
int main() {
    p2[0]=1;
    p2[1]=2;
    arr[1]=1;
    for (int i = 2; i <= 100; i++) {
        p2[i] = p2[i - 1]*2;
    }
    for (int i = 2; i <= 100; i++) {
        arr[i]= i*p2[i]-1;
    }
    long long int target;
    cin>>target;
    long long int cnt=0;
    while (target>arr[cnt+1]){cnt++;}
    cout << cnt;

}
