#include<iostream>
using namespace std;

int main(){
    int N,dir; cin>>N>>dir;
    int p[49][49];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>p[i][j];
        }
    }
    int r=(N-1)/2, c=r, two_times=0, step=1, now=0;
    for(int nothing=0;nothing<N*N;nothing++){
        cout<<p[r][c];
        switch(dir){
            case 0:
                c--;
                break;
            case 1:
                r--;
                break;
            case 2:
                c++;
                break;
            case 3:
                r++;
                break;
        }
        now++;
        if(now==step){
            dir++;
            two_times++;
            now=0;
        }
        if(two_times==2){
            step++;
            two_times=0;
        }
        if(dir==4) dir=0;
    }
}