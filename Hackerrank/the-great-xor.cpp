//https://www.hackerrank.com/challenges/the-great-xor/problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll x,ll y){
    ll temp;
    if(y==0){
        return 1;
    }
    temp = power(x,y/2);
    if(y%2==0){
        return (temp*temp);
    }else {
        if(y>0){
            return (((x*temp))*temp);
        }else {
            return ((temp*temp)/x);
        }
    }
}

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll p = n;
        ll i=0;
        while(n>0){
            i++;
            n=n/2;
        }
        ll poow = power(2,i);
        cout<<poow-p-1<<endl;
    }

}
