#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(11,vector<int>(11,0));
    int flag=1;
    for(int i=0;i<n;i++){
        int d,l,r,c;
        cin>>d>>l>>r>>c;
        if(d==0){
            if(c+l-1>10){
                flag=0;
            }
            else{
                for(int j=0;j<l;j++){
                    if(v[r][c+j]){
                        flag=0;
                    }
                    else{
                        v[r][c+j]=1;
                    }
                }
            }
        }
        else{
            if(r+l-1>10){
                flag=0;
            }
            else{
                for(int j=0;j<l;j++){
                    if(v[r+j][c]){
                        flag=0;
                    }
                    else{
                        v[r+j][c]=1;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"Y\n";
    }
    else{
        cout<<"N\n";
    }
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
