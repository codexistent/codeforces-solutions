#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
 
void solve() {
    int n, m;
    cin >> n >> m;
    cout << (long long) (m / 2) * n << endl;
}
 
int main(){
    int t; cin >> t;
    FOR(i, 1, t) solve();
}
