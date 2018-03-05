// https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/mancunian-and-beautiful-triplets-30968257/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll suffix[n];
    suffix[n-1] = a[n-1];
    for(ll i=n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],a[i]); 
    }
    set<ll> s;
    ll maxpro = 0;
    s.insert(0);
    for(ll i=0;i<n;i++){
        auto x = s.lower_bound(a[i]);
        x--;
        if(suffix[i]>a[i])
        maxpro = max(maxpro,(*x) * a[i]*suffix[i] );

        s.insert(a[i]);
    }
    cout<<maxpro<<endl;
}





