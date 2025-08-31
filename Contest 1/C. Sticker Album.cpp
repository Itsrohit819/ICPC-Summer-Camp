#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    double v=(double)(b-a+1);
    vector<double> dp(n+1,0.0), p(n+2,0.0);
    for(int i=n-1;i>=0;i--){
        int l=i+a;
        int r=i+b;
        if(l>n){
            l=n;
        }
        if(r>n){
            r=n;
        }
        double s=0.0;
        if(a==0){
            int ind=i+1;
            int cur=r;
            if(cur>n-1){
                cur=n-1;
            }
            if(ind<=cur){
                s=p[ind]-p[cur+1];
            }
            dp[i]=(v+s)/(v-1);
        }
        else{
            int cur=r;
            if(cur>n-1){
                cur=n-1;
            }
            if(l<=cur){
                s=p[l]-p[cur+1];
            }
            dp[i]=1.0+s/v;
        }
        p[i]=dp[i]+p[i+1];
    }
    cout<<fixed<<setprecision(6)<<dp[0]<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}
