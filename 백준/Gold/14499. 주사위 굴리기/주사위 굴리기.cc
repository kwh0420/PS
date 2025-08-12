    #include <bits/stdc++.h>
    using namespace std;
    int N,M,x,y,K;
    int arr[21][21];
    int instruction[1002];
    #define top 0
    #define front 1
    #define bottom 2
    #define rear 3
    #define left 4
    #define right 5
    int dir[6];

    #define east 0
    #define west 1
    #define north 2
    #define south 3
    int row[4]={0,0,-1,1};
    int col[4]={1,-1,0,0};
    int go (int mode){
    int nx = x+row[mode];
    int ny = y+col[mode];
    if (nx>=0 && nx<N && ny>=0 && ny<M){
    x=nx;
    y=ny;
    return 1;

    }
    return 0;
    }
    void dice(int mode){
    int ntop =dir[top];
    int nright = dir[right];
    int nleft = dir[left];
    int nbottom = dir[bottom];
    int nfront = dir[front];
    int nrear = dir[rear];
        if (mode==east){
        ntop = dir[left];
        nright = dir[top];
        nbottom = dir[right];
    nleft = dir[bottom];
    }
    else if (mode==west){
    ntop = dir[right];
    nright = dir[bottom];
    nbottom = dir[left];
     nleft = dir[top];
    }
    else if (mode==north){
     ntop = dir[front];
     nfront = dir[bottom];
     nbottom = dir[rear];
     nrear = dir[top];
    }
    else if (mode==south){
     ntop = dir[rear];
    nfront = dir[top];
     nbottom = dir[front];
     nrear = dir[bottom];
    }
    dir[top] = ntop;
    dir[right] = nright;
    dir[bottom] = nbottom;
    dir[front] = nfront;
    dir[rear] = nrear;
    dir[left] = nleft;
    }
    int main(){
        cin >> N >> M >> x >> y >> K;
        for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
        cin >> arr[i][j];
    }
    }
    for (int i=0; i<K; i++){
    cin >> instruction[i];
    }
    for (int i=0; i<K; i++){
        if (go(instruction[i]-1)){
            dice(instruction[i]-1);
        if (arr[x][y]==0){
            arr[x][y]=dir[bottom];
        }
        else{
            dir[bottom]=arr[x][y];
            arr[x][y]=0;
        }
    }
    else {
        continue;
        }
        cout << dir[top] << "\n";


}
    }
