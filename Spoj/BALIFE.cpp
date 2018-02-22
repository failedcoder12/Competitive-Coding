//http://www.spoj.com/problems/BALIFE/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n;
    while (1) {
        cin >> n;
        if(n==-1){
            return 0;
        }
        ll a[n];
        ll loadreq = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            loadreq += a[i];
        }
        if(loadreq % n){
            cout<<-1<<endl;
            continue;
        }
        loadreq = loadreq / n;

        ll diff = 0;
        ll maxxans = INT_MIN;

        for (ll i = 0; i < n; i++) {
            diff += (a[i] - loadreq);
            if (diff < 0) {
                maxxans = max(maxxans, -1 * diff);
            } else {
                maxxans = max(maxxans, diff);
            }
        }
        cout << maxxans << endl;
    }
}


// In all the partitions where less than max_load is transferred, we can
// internally transfer the load between these partitions when max_laod is
// being transferred between the max_load partition