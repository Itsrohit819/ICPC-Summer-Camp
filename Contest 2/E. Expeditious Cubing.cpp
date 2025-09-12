#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    long double t1,t2,t3,t4,T;
    cin >> t1 >> t2 >> t3 >> t4;
    cin >> T;
    vector<long double> v = {t1,t2,t3,t4};
    sort(v.begin(),v.end());
    long double a = v[0];
	long double d = v[3];
	long double s = v[0]+v[1]+v[2]+v[3];
    long double lim = 3.0L*T;
    if (s-d > lim+1e-12L) {
        cout << "impossible\n";
        return 0;
    }
    if (s-a <= lim+1e-12L) {
        cout << "infinite\n";
        return 0;
    }
    long double x = lim-s+a+d;
    cout << fixed << setprecision(2) << (double)x << "\n";
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
    	solve();
	}
}
