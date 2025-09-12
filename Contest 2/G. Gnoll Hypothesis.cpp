#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(){
    int n,k;
    cin >> n >> k;
    vector<long double> s(n+1),eff(n+1);
    for(int i=1;i<=n;i++) cin >> s[i];
    vector<vector<long double>> C(n+1,vector<long double>(n+1));
    for(int a=0;a<=n;a++){
        C[a][0]=C[a][a]=1;
        for(int b=1;b<a;b++){
            C[a][b]=C[a-1][b-1]+C[a-1][b];
        }
    }
    long double D=C[n][k];
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            int d=(i-j+n)%n;
            long double w=0;
            if(d==0){
                if(k-1<=n-1) w=C[n-1][k-1];
            }
            else{
                int r=n-d-1;
                if(r>=k-1) w=C[r][k-1];
            }
            if(w>0){
                eff[i]+=s[j]*w/D;
            }
        }
    }
    cout<<fixed<<setprecision(9);
    for(int i=1;i<=n;i++) cout<<(double)eff[i]<<" ";
    cout<<"\n";
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
