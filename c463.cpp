#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    int tree[100001]={},root[100001]={},high[100001]={};
    //tree[子]=父
    vector<int> son(0),parent(0);
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        if(k==0){
            son.push_back(i);
            continue;
        }
        for(int nothing=0;nothing<k;nothing++){
            int a; cin>>a;
            tree[a]=i;
            root[a]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(root[i]==0){
            cout<<i<<endl;
            break;
        }
    }
    int i=0,h=1;
    while(tree[son[0]]||son.size()-1){
        int a=son[i];
        if(i==0 || parent[i-1]!=tree[a]) parent.push_back(tree[a]);
        high[tree[a]]=h;
        i++;
        if(i==son.size()){
            i=0;
            son=parent;
            parent.resize(0);
            h++;
        }
    }
    int HT=0;
    for(int i=1;i<=n;i++){
        HT+=high[i];
    }
    cout<<HT;
}