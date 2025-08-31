#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s=0,mx=0;
    for(int i=0;i<n;i++){
        s+=a[i];
        mx = max(mx,s);
    }
    cout<<100+mx<<"\n";
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
