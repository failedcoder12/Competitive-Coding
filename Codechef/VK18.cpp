
//https://www.codechef.com/DEC17/problems/VK18/

//Pata nahi kaise submit ho gaya but ho gaya

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 2000000
#define M 1000000
ll eo(ll x){
    ll a=0,b=0;
    while(x){
        b=x%10;
        if(b%2==0){
            a=a+b;
        } else {
            a = a-b;
        }
        x=x/10;
    }
    return abs(a);
}
 
 
ll x[M] = {0};
ll dp[MAX] = {0};
 
ll op(ll i){
    if(dp[i] == 0)
        return dp[i] = eo(i);
    return dp[i];
}
 
ll aaa(ll xx){
    x[1] = 2;
    if(x[xx] != 0)
        return x[xx];
    ll i = xx-1;
    return  x[i+1] = aaa(i)+aaa(i)-aaa(i-1)-2*op(i+1) + op(2*(i))+2*op(2*i + 1)+op(2*i+2);
}
 
int main() {
    x[2] = 12;
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        cout<<aaa(n)<<endl;
    }
} 