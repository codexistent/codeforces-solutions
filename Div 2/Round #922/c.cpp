#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(long long i = a; i <= b; i++)
#define ll long long

ll solve2(ll a, ll b, ll r){ // wlog assume a > b
    ll pow = 1;
    int dig = 1; while (max(a, max(b, r)) >= pow * 2) dig++, pow *= 2;

    ll dp[62][2];
    FOR(i, 1, 61) dp[i][0] = dp[i][1] = LLONG_MAX;
    dp[dig + 1][1] = 0; // dp[i][0] == less than r up to dig i, dp[i][1] = eq to r up to dig i

    for(int d = dig; d >= 1; d--, pow /= 2){
        ll ad = (a & pow), bd = (b & pow);
        if(pow > r) { // r dig must be 0
            if(dp[d + 1][1] != LLONG_MAX && dp[d + 1][1] + (ad ^ 0) - (bd ^ 0) >= 0) dp[d][1] = dp[d + 1][1] + (ad ^ 0) - (bd ^ 0);
            continue;
        }

        ll r0 = (ad ^ 0) - (bd ^ 0), r1 = (ad ^ pow) - (bd ^ pow);
        if(r & pow){
            // choose r digit = 0
            if(dp[d + 1][1] != LLONG_MAX && dp[d + 1][1] + r0 >= 0) dp[d][0] = min(dp[d][0], dp[d + 1][1] + r0);
            if(dp[d + 1][0] != LLONG_MAX && dp[d + 1][0] + r0 >= 0) dp[d][0] = min(dp[d][0], dp[d + 1][0] + r0);
            // choose r digit = 1
            if(dp[d + 1][1] != LLONG_MAX && dp[d + 1][1] + r1 >= 0) dp[d][1] = min(dp[d][1], dp[d + 1][1] + r1);
            if(dp[d + 1][0] != LLONG_MAX && dp[d + 1][0] + r1 >= 0) dp[d][0] = min(dp[d][0], dp[d + 1][0] + r1);
        }else{
            // choose r digit = 0
            if(dp[d + 1][1] != LLONG_MAX && dp[d + 1][1] + r0 >= 0) dp[d][1] = min(dp[d][1], dp[d + 1][1] + r0);
            if(dp[d + 1][0] != LLONG_MAX && dp[d + 1][0] + r0 >= 0) dp[d][0] = min(dp[d][0], dp[d + 1][0] + r0);
            // choose r digit  1
            if(dp[d + 1][0] != LLONG_MAX && dp[d + 1][0] + r1 >= 0) dp[d][0] = min(dp[d][0], dp[d + 1][0] + r1);
        }
    }

    return min(dp[1][0], dp[1][1]);
}

void solve() {
    ll a, b, r, ans = 0, pow = 1;
    cin >> a >> b >> r;
    cout << min(solve2(a, b, r), solve2(b, a, r)) << endl;
} 

int main(){
    int t; cin >> t;
    FOR(i, 1, t) solve();
}
