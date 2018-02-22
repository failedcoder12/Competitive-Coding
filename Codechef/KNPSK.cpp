//https://www.codechef.com/problems/KNPSK
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
    ll n;
    cin>>n;
    vector<ll> one;
    vector<ll> two;
    ll M=0;
    for(ll i=0;i<n;i++){
        ll type,cost;
        cin>>type>>cost;
        M+=type;
        if(type == 1){
            one.push_back(cost);
        }else {
            two.push_back(cost);
        }
    }
    ll costs[M+1] = {0};
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    
    vector<ll> ONE = one;
    vector<ll> TWO = two;
    ll ans1=0;
    for(ll i=2;i<=M;i+=2){
        if(two.empty() ||one.size() > 1 && one[one.size()-1]+one[one.size()-2] > two[two.size()-1]){
            ans1+=one[one.size()-1]+one[one.size()-2];
            one.pop_back();
            one.pop_back();
        }
        else if(two.empty() ||one.size() > 0 && one[one.size()-1] > two[two.size()-1]){
            ans1+=one[one.size()-1];
            one.pop_back();
        }
        else {
            ans1+=two[two.size()-1];
            two.pop_back();
        }
        costs[i] = ans1;
    }
    ll ans2=0;
    if(!ONE.empty()){
        ans2 = ONE[ONE.size()-1];
        ONE.pop_back();
        costs[1] = ans2;
    }
    for(ll i=3;i<=M;i+=2){
        if(TWO.empty() ||ONE.size() > 1 && ONE[ONE.size()-1]+ONE[ONE.size()-2] > TWO[TWO.size()-1]){
            ans2+=ONE[ONE.size()-1]+ONE[ONE.size()-2];
            ONE.pop_back();
            ONE.pop_back();
        }else if(TWO.empty() ||ONE.size() > 0 && ONE[ONE.size()-1] > TWO[TWO.size()-1]){
            ans2+=ONE[ONE.size()-1];
            ONE.pop_back();
        }
        else  {
            ans2+=TWO[TWO.size()-1];
            TWO.pop_back();
        }
        costs[i] = ans2;
    }
    for(ll i=1;i<=M;i++){
        cout<<costs[i]<<" ";
    }
    cout<<endl;
}