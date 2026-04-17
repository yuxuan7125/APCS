#include<iostream>
using namespace std;
bool line[10000000]={};

int main(){
    int n,a,b,as=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int k=a;k<b;k++){
            if(!line[k]){
                line[k]=1;
                as++;
            }
        }
    }
    cout<<as;
}