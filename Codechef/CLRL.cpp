
//https://www.codechef.com/NOV17/problems/CLRL

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++) {
        ll n, last;
        cin >> n >> last;
        ll a[n];
        for (ll j = 0; j < n; j++) {
            cin >> a[j];
        }
        if (a[n - 1] != last) {
            cout << "NO" << endl;
            continue;
        }
        ll p=0;
        ll min = INT_MIN, max = INT_MAX;
        for(ll j=0;j<n;j++){
            if(a[j]==last)
                break;
            if(a[j]<min||a[j]>max){
                cout<<"NO"<<endl;
                p=1;
                break;
            }
            if(a[j]<last){
                min = a[j];
            } else {
                max = a[j];
            }
        }
        if(p==1)
            continue;
        cout<<"YES"<<endl;
    }
}