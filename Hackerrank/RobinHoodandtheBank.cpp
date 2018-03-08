// https://www.hackerrank.com/contests/nitk-cp-league-contest1/challenges/robin-hood-and-the-bank/problem

#include <bits/stdc++.h>
using namespace std;
#define ll int

bool check(double val, double a[],ll n, double m){
    double greater = 0,smaller = 0;

    for(ll i=0;i<n;i++){
        if(a[i] >= val){
            greater+= (a[i]-val);
        }else {
            smaller+= (val-a[i]);
        }
    }

    double smallerexpect = greater - greater*m/100.0;
    return smallerexpect >= smaller;
}

double binary(double s,double e, double a[],ll n,double m){
    if(s>=e){
        return e;
    }
    double ee = 1e-7;
    double mid = (e+s)/2.00;
    if(!check(mid,a,n,m)){
        return binary(s,mid-ee,a,n,m);
    }else {
        return binary(mid+ee,e,a,n,m);
    }
}
int main() {
    ll n;double m;
    cin>>n>>m;
    double a[n];
    double mini = 1e5;
    double maxx = 0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mini = min(mini,a[i]);
        maxx = max(maxx,a[i]);
    }
    cout.precision(9);
    cout<<fixed<<binary(mini,maxx,a,n,m)<<endl;
}