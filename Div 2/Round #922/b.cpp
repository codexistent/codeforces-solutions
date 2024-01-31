#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    FOR(i, 0, n - 1) cin >> a[i];
    FOR(i, 0, n - 1) cin >> b[i];
    
    set<pair<double, pair<int, int>>> p;
    FOR(i, 0, n - 1) p.insert(make_pair((a[i] + b[i]) / 2, make_pair(a[i], b[i])));
    for(auto i : p) cout << i.second.first << " ";
    cout << endl; 
    for(auto i : p) cout << i.second.second << " ";
    cout << endl; 
}
 
int main(){
    int t; cin >> t;
    FOR(i, 1, t) solve();
}
