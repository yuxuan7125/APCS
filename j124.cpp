#include<iostream>
#include<vector>
#include<cmath>
#include<array>
using namespace std;

int main(){
    vector<array<int,2>> path={{0,0}};
    int son,i=0;
    long long ans=0;
    while(cin>>son){
        int parent=path[i][0];
        path[i][1]--;
        if(path[i][1]==0){
            path.resize(i);
            i--;
        }
        if(son){
            path.push_back({son,son%2+2});
            if(parent) ans+=abs(son-parent);
            i++;
        }
    }
    cout<<ans;
}