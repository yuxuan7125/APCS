#include<iostream>
using namespace std;

long long p[50001]={0};
long long sum[50001]={0};
int K;

long long Div(int head,int tail,long long r,int k){
    if(k==K){return 0;}
    k++;
    if(tail-head<2){return 0;}
    long long l=0;
    long long past=r-l;
    int j=0;
    long long next_r=0;
    for(int i=head+1;i<tail;i++){
        l+=(sum[i-1]-sum[head-1]);
        r-=(sum[tail]-sum[i-1]);
        long long now=r-l;
        if(now<=0){
            if(past<=-now){  //i-1
                if(i!=head+1)   return p[i-1]+Div(head,i-2,next_r,k)+Div(i,tail,r,k);
            }
               //i
            next_r+=p[i-1]*j++;
            return p[i]+Div(head,i-1,next_r,k)+Div(i+1,tail,r-(sum[tail]-sum[i]),k);
            
        }
        past=r-l;
        next_r+=p[i-1]*j++;
    }
    return p[tail-1]+Div(head,tail-2,next_r,k);
}

int main(){
    int N;    cin>>N>>K;
    long long r=0;
    for(int i=1;i<=N;i++){
        cin>>p[i];
        r+=(i-1)*p[i];
        sum[i]=sum[i-1]+p[i];
    }
    cout<<Div(1,N,r,0);
}