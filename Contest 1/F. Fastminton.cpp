#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int c = 0, d = 0;
    int a = 0, b = 0;
    int cnt = 0;
    bool flag = false;

    for(char x : s){
        if((c >= 5 && c - d >= 2) || c == 10){
            a++;
            c = 0;
            d = 0;
            cnt = 0;
        }
        else if((d >= 5 && d - c >= 2) || d == 10){
            b++;
            c = 0;
            d = 0;
            cnt = 1;
        }
		if(x == 'S'){
            if(cnt == 0){
                c++;
            }
            else{
                d++;
            }
        }
        if(x == 'R'){
            if(cnt == 0){
                d++;
            }
            else{
                c++;
            }
            cnt = 1 - cnt;
        }
        if(x == 'Q'){
            if(a == 2){
                cout << a << " (winner) - " << b << "\n";
                flag = true;
            }
            else if(b == 2){
                cout << a << " - " << b << " (winner)" << "\n";
                flag = true;
            }
            else{
                if(cnt == 0){
                    cout << a << " (" << c << "*) - " << b << " (" << d << ")" << "\n";
                }
                else{
                    cout << a << " (" << c << ") - " << b << " (" << d << "*)" << "\n";
                }
            }
        }
    }
}
