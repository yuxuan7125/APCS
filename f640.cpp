#include<iostream>
#include<string>
using namespace std;

long long f();
long long g();
long long h();

long long f(){
    long long x;
    string a;
    cin>>a;
    if(a=="f")  x=f();
    else if(a=="g")  x=g();
    else if(a=="h")  x=h();
    else  x=stoll(a);
    return 2*x-3;
}

long long g(){
    long long x,y;
    for(int i=0;i<2;i++){
        string a;
        long long k;
        cin>>a;
        if(a=="f")  k=f();
        else if(a=="g")  k=g();
        else if(a=="h")  k=h();
        else  k=stoll(a);

        if(i==0) x=k;
        else y=k;
    }
    return 2*x+y-7;
}

long long h(){
    long long x,y,z;
    for(int i=0;i<3;i++){
        string a;
        long long k;
        cin>>a;
        if(a=="f")  k=f();
        else if(a=="g")  k=g();
        else if(a=="h")  k=h();
        else  k=stoll(a);

        if(i==0) x=k;
        else if(i==1) y=k;
        else z=k;
    }
    return 3*x-2*y+z;
}

int main(){
    string n;
    cin>>n;
    if(n=="f")  cout<<f();
    else if(n=="g") cout<<g();
    else cout<<h();
}