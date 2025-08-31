#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int q;
    cin>>q;
    vector<string> w(q);
    for(int i=0;i<q;i++){
        cin>>w[i];
    }
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<q;i++){
        string s=w[i];
        int p=s.size();
        vector<int> need(26,0);
        for(int j=0;j<p;j++){
            need[s[j]-'A']++;
        }
        vector<vector<int>> b(n,vector<int>(m,0));
        if(m>=p){
            for(int r=0;r<n;r++){
                vector<int> cnt(26,0);
                for(int j=0;j<p;j++){
                    cnt[g[r][j]-'A']++;
                }
                if(cnt==need){
                    for(int k=0;k<p;k++){
                        b[r][k]=1;
                    }
                }
                for(int j=p;j<m;j++){
                    cnt[g[r][j-p]-'A']--;
                    cnt[g[r][j]-'A']++;
                    if(cnt==need){
                        for(int k=j-p+1;k<=j;k++){
                            b[r][k]=1;
                        }
                    }
                }
            }
        }
        if(n>=p){
            for(int c=0;c<m;c++){
                vector<int> cnt(26,0);
                for(int j=0;j<p;j++){
                    cnt[g[j][c]-'A']++;
                }
                if(cnt==need){
                    for(int k=0;k<p;k++){
                        b[k][c]=1;
                    }
                }
                for(int j=p;j<n;j++){
                    cnt[g[j-p][c]-'A']--;
                    cnt[g[j][c]-'A']++;
                    if(cnt==need){
                        for(int k=j-p+1;k<=j;k++){
                            b[k][c]=1;
                        }
                    }
                }
            }
        }
        for(int d=-(n-1);d<=m-1;d++){
            vector<pair<int,int>> pos;
            string t="";
            for(int r=0;r<n;r++){
                int c=r+d;
                if(c>=0&&c<m){
                    pos.push_back({r,c});
                    t.push_back(g[r][c]);
                }
            }
            int sz=pos.size();
            if(sz<p) continue;
            vector<int> cnt(26,0);
            for(int j=0;j<p;j++){
                cnt[t[j]-'A']++;
            }
            if(cnt==need){
                for(int k=0;k<p;k++){
                    b[pos[k].first][pos[k].second]=1;
                }
            }
            for(int j=p;j<sz;j++){
                cnt[t[j-p]-'A']--;
                cnt[t[j]-'A']++;
                if(cnt==need){
                    for(int k=j-p+1;k<=j;k++){
                        b[pos[k].first][pos[k].second]=1;
                    }
                }
            }
        }
        for(int d=0;d<=n+m-2;d++){
            vector<pair<int,int>> pos;
            string t="";
            for(int r=0;r<n;r++){
                int c=d-r;
                if(c>=0&&c<m){
                    pos.push_back({r,c});
                    t.push_back(g[r][c]);
                }
            }
            int sz=pos.size();
            if(sz<p) continue;
            vector<int> cnt(26,0);
            for(int j=0;j<p;j++){
                cnt[t[j]-'A']++;
            }
            if(cnt==need){
                for(int k=0;k<p;k++){
                    b[pos[k].first][pos[k].second]=1;
                }
            }
            for(int j=p;j<sz;j++){
                cnt[t[j-p]-'A']--;
                cnt[t[j]-'A']++;
                if(cnt==need){
                    for(int k=j-p+1;k<=j;k++){
                        b[pos[k].first][pos[k].second]=1;
                    }
                }
            }
        }
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(b[r][c]){
                    a[r][c]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]>=2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}
