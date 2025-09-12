#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
    }
    int p;
    cin >> p;
    set<int> st;
    for(int i=0;i<p;i++){
        int x; 
		cin >> x;
        st.insert(x);
    }
    vector<int> v;
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
    	int a = l[i];
    	int b = r[i];
        auto it = st.lower_bound(a);
        while(it != st.end() && *it <= b){
            cnt[i]++;
            it++;
        }
    }
    for(int i=0;i<n;i++){
    	int a = l[i];
    	int b = r[i];
        if(cnt[i] > 2){
            cout << "impossible\n";
            return 0;
        }
        while(cnt[i] < 2){
            int temp = 0;
            for(int j=b;j>=a;j--){
                if(st.find(j) != st.end()){
                	continue;
                }
                int flag = 1;
                if(i > 0 && j >= l[i-1] && j <= r[i-1]){
                    if(cnt[i-1] == 2){
						flag = 0;
					}
                }
                if(i+1 < n && j >= l[i+1] && j <= r[i+1]){
                    if(cnt[i+1] == 2){
						flag = 0;
					}
                }
                if(!flag){
					continue;
				}
                st.insert(j);
                v.push_back(j);
                cnt[i]++;
                if(i > 0 && j >= l[i-1] && j <= r[i-1]){
					cnt[i-1]++;
				}
                if(i+1 < n && j >= l[i+1] && j <= r[i+1]){
					cnt[i+1]++;
				}
                temp = 1;
                break;
            }
            if(!temp){
                cout << "impossible\n";
                return 0;
            }
        }
    }
    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
}
