#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int l = 0;
    while(l<n && a[l]==b[l]){
        l++;
    }
    if(l == n){
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    int r = n - 1;
    while(r >= 0 && a[r] == b[r]){
        r--;
    }
    reverse(a.begin() + l, a.begin() + r + 1);
    if(a == b){
        cout << l+1 << " " << r+1 << "\n";
    }
    else{
        cout << "impossible\n";
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
}
