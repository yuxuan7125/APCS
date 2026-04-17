#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main(){
    int n,m,k=0;
    vector<pair<int,int>> k_list;
    cin>>n>>m;
    int p[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a=p[i][j],count=0;
            for(int r=-a;r<=a;r++){
                if (r<=0)
                    for(int c=-a-r;c<=a+r;c++){
                        if (i+r>=0 && i+r<n && j+c>=0 && j+c<m) count+=p[i+r][j+c];
                    }
                else
                    for(int c=r-a;c<=a-r;c++){
                        if (i+r>=0 && i+r<n && j+c>=0 && j+c<m) count+=p[i+r][j+c];
                    }
            }
            if (a==count%10){
                k++;
                k_list.push_back(make_pair(i,j));
            }
        }
    }

    cout<<k;
    for(pair<int,int> x : k_list){
        cout<<endl<<x.first<<" "<<x.second;
    }
}