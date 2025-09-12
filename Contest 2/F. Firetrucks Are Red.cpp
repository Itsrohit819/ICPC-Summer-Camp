#include <bits/stdc++.h>
#define int long long
using namespace std;

int check(vector<int>& p,int x){
    if(p[x]==x){
		return x;
	}
    return p[x]=check(p,p[x]);
}

int solve(){
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
    }
    vector<int> p(n),r(n,0);
    iota(p.begin(),p.end(),0);
    vector<array<int,3>> ans;
    for(auto &kv:mp){
        auto &v=kv.second;
        if(v.size()<2) continue;
        int u=v[0];
        for(int k=1;k<v.size();k++){
            int a=check(p,u),b=check(p,v[k]);
            if(a!=b){
                if(r[a]<r[b]) swap(a,b);
                p[b]=a;
                if(r[a]==r[b]) r[a]++;
                ans.push_back({u,v[k],kv.first});
                if(ans.size()==n-1) break;
            }
        }
        if(ans.size()==n-1) break;
    }
    int rt=check(p,0);
    for(int i=1;i<n;i++){
        if(check(p,i)!=rt){
            cout << "impossible\n";
            return 0;
        }
    }
    for(auto &e:ans){
        cout << e[0]+1 << " " << e[1]+1 << " " << e[2] << "\n";
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}
