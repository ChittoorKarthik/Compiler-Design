#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn for(int i=0;i<n;i++)

const int big=1e5+2;

vector<int>leader(big);
map<int,bool>isinfected;
vector<int>ans(big);
vector<vector<int>>children(big,vector<int>(0,{}));


int main(){

int n,m;
cin>>n>>m;
vector<int>initialinf(m);
for(int i=0;i<m;i++){
    cin>>initialinf[i];
    isinfected[initialinf[i]]=true;
    ans[isinfected[i]]=0;
}

for(int i=0;i<n;i++){
    leader[i]=i;
}

int q;
cin>>q;
int time=0;
while(q--){
    time++;
    int type,a,b;
    cin>>type>>a>>b;
    if(type==0){  //contact - merge
        leader[leader[min(a,b)]]=leader[max(a,b)];
        if(isinfected[a] && !isinfected[b]){
            isinfected[b]=true;
            ans[b]=time;
        }
        else if(isinfected[b] && !isinfected[a]){
            isinfected[a]=true;
            ans[a]=time;
        }
    }

}

return 0;
}