// https://www.hackerrank.com/challenges/truck-tour/problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

queue<pair<ll,ll>> q;

int main(){
    ll n;
    cin>>n;
    ll petrol[n];
    ll dis[n];

    for(ll i=0;i<n;i++){
        cin>>petrol[i]>>dis[i];
        q.push(make_pair(petrol[i],dis[i]));
    }
    ll passed = 0;
    ll inipetrol = 0;
    ll start = 0;
    while(passed < n){
        pair<ll,ll> p;
        p.first = q.front().first;
        p.second = q.front().second;
        q.pop();
        inipetrol += p.first;
        if(inipetrol >= p.second){
            passed +=1;
            inipetrol -= p.second;
        }else {
            start +=passed+1;
            passed = 0;
            inipetrol = 0;
        }
        q.push(make_pair(p.first,p.second));
    }
    cout<<start<<endl;

}
