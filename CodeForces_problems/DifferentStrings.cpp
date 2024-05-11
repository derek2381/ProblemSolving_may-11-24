// problem link
// https://codeforces.com/problemset/problem/1971/B


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string str, res;
        cin >> str;
        int n = str.length();
        res = str;

        for(int i = 1; i <n;i++){
            if(res[i] != res[i-1]){
                swap(res[i], res[i-1]);
            }
        }

        if(res != str){
            cout << "YES\n";
            cout << res << endl;
        }
        else{
            cout << "NO\n";
        }
    }
}
