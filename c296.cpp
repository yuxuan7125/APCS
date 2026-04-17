#include<iostream>
using namespace std;

int main(){
    int N,M,K,now=0,count,bomb;
    cin>>N>>M>>K;
    int n=N,p[N]={};
    for(int nothing=0;nothing<K;nothing++){
        count=0;
        bomb=M%n;
        if(bomb==0) bomb=n;
        if(bomb<=n/2){
            while(count<bomb){
                if(p[now]==0) count++;
                now++;
                if(now==N) now=0;
            }
            cout<<"A";
        }
        else{
            while(count<(n-bomb+3)){
                if(p[now]==0) count++;
                now--;
                if(now==-1) now=N-1;
            }
            now+=2;
            if(now>=N) now-=N;
            cout<<"B";
        }
        if(now>0) p[now-1]=1;
        else p[N-1]=1;
        n--;
        for(int x:p) cout<<x<<" ";
        cout<<"\n";
    }
    while(p[now]==1){
        now++;
        if (now==N) now=0;
    }
    cout<<now+1;
}