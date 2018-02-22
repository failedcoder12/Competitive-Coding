#include <bits/stdc++.h>
using namespace std;

int lcs(string a,string b,int aa,int bb){

    int dp[aa+1][bb+1];

    int a1 = aa;
    int b1 = bb;
    for(int i=0;i<=aa;i++){
        for(int j=0;j<=bb;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            }else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string ans = "";

    while(aa>=0&&bb>=0){
        if(a[aa-1] == b[bb-1]){
            ans+=a[aa-1];
            aa--;bb--;
        }else {
            if(dp[aa-1][bb] > dp[aa][bb-1]){
                aa--;
            }else {
                bb--;
            }
        }
    }
   reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

    return dp[a1][b1];
}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    cout<<lcs(a,b,a.length(),b.length())<<endl;
}