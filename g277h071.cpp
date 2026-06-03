#include<iostream>

using namespace std;
using ll=long long;

ll p[300001];
ll ind[10000001]={0};
ll sum[300001]={0};
ll small=1;

ll solve(ll L,ll R){
    ll l,r;
    if(R==L) return p[L];
    while(true){
        if(ind[small]==0){
            small++;
            continue;
        }
        ll i=ind[small];
        if(i==L) return solve(i+1,R);
        if(i==R) return solve(L,i-1);
        if(i>L && i<R){
            l=i+1;
            r=i-1;
            small++;
            break;
        }
        small++;
    }
    ll L_sum=sum[r]-sum[L-1];
    ll R_sum=sum[R]-sum[l-1];
    if(L_sum>R_sum) return solve(L,r);
    else return solve(l,R);
}

int main(){
    ll N;
    cin>>N;
    for(ll i=1;i<=N;i++){
        ll x;
        cin>>x;
        p[i]=x;
        ind[x]=i;
        sum[i]=sum[i-1]+x;
    }
    cout<<solve(1,N);
}