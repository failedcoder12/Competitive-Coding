#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll calculateMex(unordered_set<int> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}

ll calculateGrundy(ll n){
    if(n==0)
        return 0;
    unordered_set<int> Set;
    for(ll i=0;i<n;i++){
        Set.insert(calculateGrundy(i));
    }
    return calculateMex(Set);
}

ll calculateGrundy123(ll n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 3;
    unordered_set<int> Set;
    for(ll i=1;i<=3;i++){
        Set.insert(calculateGrundy123(n-i));
    }
    return calculateMex(Set);
}


ll calculateGrundy236(ll n){
    if(n==0)
        return 0;
    unordered_set<int> Set;
    Set.insert(calculateGrundy236(n/2));
    Set.insert(calculateGrundy236(n/3));
    Set.insert(calculateGrundy236(n/6));

    return calculateMex(Set);
}

int main() {
    ll n=10;
    cout<<calculateGrundy(n)<<endl;
    cout<<calculateGrundy123(n)<<endl;
    cout<<calculateGrundy236(n)<<endl;
    return 0;
}