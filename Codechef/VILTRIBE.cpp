
// https://www.codechef.com/NOV17/problems/VILTRIBE

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll a=0,c=0;
        ll coa=0,cob=0,cc=0;
        string s;
        cin>>s;
        ll len = 0;
        while(len<s.length()){
            if(s[len]=='A'){
                coa++;
            }if(s[len]=='B'){
                cob++;
            }
            if(s[len]=='.'&&c==0){
                len++;
            }else if(c==0&&s[len]=='A'){
                c=1;
                a=0;
                cc=0;
                len++;
            }else if(c==0&&s[len]=='B'){
                c=1;
                a=1;
                cc=0;
                len++;
            }else if(s[len]=='.'){
                cc++;
                len++;
            }else if(s[len]=='A'&&a==0){
                a=0;
                coa+=cc;
                cc=0;
                len++;
            }else if(s[len]=='A'&&a==1){
                a=0;
                cc=0;
                len++;
            }else if(s[len]=='B'&&a==1){
                a=1;
                cob+=cc;
                cc=0;
                len++;
            }else if(s[len]=='B'&&a==0) {
                a = 1;
                cc = 0;
                len++;
            }
        }
        cout<<coa<<" "<<cob<<endl;
    }
}