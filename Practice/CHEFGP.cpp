// https://www.codechef.com/OCT17/problems/CHEFGP

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll x,y;
        cin>>x>>y;
 
        // Count number of a's and b's
 
        ll acount = 0,bcount = 0;
        for(ll i=0;i<s.length();i++){
            if(s[i] == 'a'){
                acount++;
            }else {
                bcount++;
            }
        }
        string ans = "";
        while(acount > 0 && bcount >0){
            if(acount > bcount){
                //decreasing acount to bcount or acount to 0
                for(ll j=0;j < min(x,acount - bcount +1);j++){
                    ans+='a';
                }
                ans+='b';
                acount-=min(x,acount-bcount+1);
                bcount--;
            }
            else if(acount < bcount){
                //decreasing acount to bcount or acount to 0
                for(ll j=0;j < min(y,bcount - acount +1);j++){
                    ans+='b';
                }
                ans+='a';
                bcount-=min(y,bcount-acount+1);
                acount--;
            }else {
                break;
            }
        }
        if(acount > 0 && bcount > 0){
            string o = "ab";
            if(!ans.empty() && ans[0] == 'b'){
                o = "ba";
            }
            for(ll i=0;i<acount;i++){
                ans+=o;
            }
            cout<<ans<<endl;
            continue;
        }        
        for(ll i=0;i<acount;i++){
            if(i !=0 && i%x == 0){
                ans+='*';
            }
            ans+='a';
        }
 
        for(ll i=0;i<bcount;i++){
            if(i!=0 && i%y == 0){
                ans+='*';
            }
            ans+='b';
        }
        cout<<ans<<endl;
    }
}