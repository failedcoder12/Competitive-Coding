
//https://www.codechef.com/NOV17/problems/CHEFHPAL

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n,a;
        cin>>n>>a;
        if(a==1){
            cout<<n<<" ";
            for(ll j=0;j<n;j++){
                cout<<"a";
            }
        }else if(a==2&&n==2){
            cout<<"1 ";
            cout<<"ab";
        }else if(a==2&&n==3){
            cout<<"2 ";
            cout<<"aab";
        }else if(a==2&&n==4){
            cout<<"2 ";
            cout<<"aabb";
        }else if(a==2&&n==5){
            cout<<"3 ";
            cout<<"aaabb";
        }else if(a==2&&n==6){
            cout<<"3 ";
            cout<<"aaabbb";
        }else if(a==2&&n==7){
            cout<<"3 ";
            cout<<"aaababb";
        }else if(a==2&&n==8){
            cout<<"3 ";
            cout<<"aaababbb";
        }else if(a==2&&n==1){
            cout<<"1 a";
        }
        else if(a==2){
            cout<<"4 ";
            for(ll j=0;j<n;j++){
                if(j<n)
                {
                    cout<<"a";
                    j++;
                }if(j<n)
                {
                    cout<<"b";
                    j++;
                }if(j<n)
                {
                    cout<<"b";
                    j++;
                }if(j<n)
                {
                    cout<<"a";
                    j++;
                }if(j<n)
                {
                    cout<<"a";
                    j++;
                }if(j<n)
                {
                    cout<<"b";
                    j++;
                }
            }
        }else {
            cout<<"1 ";
            for(ll j=0;j<n;j++){
                if(j<n)
                {
                    cout<<"a";
                    j++;
                }if(j<n)
                {
                    cout<<"b";
                    j++;
                }if(j<n)
                {
                    cout<<"c";
                    j++;
                }
            }
        }
        cout<<endl;
    }
}