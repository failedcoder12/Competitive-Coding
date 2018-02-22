//http://codeforces.com/contest/429/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main() {
    ll m, n;
    cin>>m>>n;
    ll calorie[m + 1][n + 1];
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> calorie[i][j];
        }
    }

    ll boy_start[m + 2][n + 2];
    ll boy_end[m + 2][n + 2];
    ll girl_start[m + 2][n + 2];
    ll girl_end[m + 2][n + 2];

    memset(boy_start, 0, sizeof(boy_start));
    memset(girl_start, 0, sizeof(girl_start));
    memset(boy_end, 0, sizeof(boy_end));
    memset(girl_end, 0, sizeof(girl_end));

    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            boy_start[i][j] = calorie[i][j] + max(boy_start[i - 1][j], boy_start[i][j - 1]);
        }
    }
    for (ll i = m; i >= 1; i--) {
        for (ll j = 1; j <= n; j++) {
            girl_start[i][j] = calorie[i][j] + max(girl_start[i + 1][j], girl_start[i][j - 1]);
        }
    }
    for (ll i = m; i >= 1; i--) {
        for (ll j = n; j >= 1; j--) {
            boy_end[i][j] = calorie[i][j] + max(boy_end[i + 1][j], boy_end[i][j + 1]);
        }
    }
    for (ll i = 1; i <= m; i++) {
        for (ll j = n; j >=1; j--) {
            girl_end[i][j] = calorie[i][j] + max(girl_end[i - 1][j], girl_end[i][j + 1]);
        }
    }
    ll ans = 0;

    for (ll i = 2; i < m; i++) {
        for (ll j = 2; j < n; j++) {
            ll a1 = boy_start[i][j - 1] + boy_end[i][j + 1] + girl_start[i + 1][j] + girl_end[i - 1][j];
            ll a2 = boy_start[i - 1][j] + boy_end[i + 1][j] + girl_start[i][j - 1] + girl_end[i][j + 1];
            ans = max(ans, max(a1, a2));
        }
    }
    cout<<ans<<endl;
}

