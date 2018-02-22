        //https://www.codechef.com/JAN18/problems/KCON/

        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long int
        ll max_sub_array(ll a[],ll n){
        ll ms = a[0];
        ll cs = a[0];
        for(ll i=1;i<n;i++){
            cs = max(a[i],cs+a[i]);
            ms = max(ms,cs);
        }
        return ms;
    }
         
        int main(){
            ll t;
            cin>>t;
            while(t--){
                ll n,k;
         
                cin>>n>>k;
         
                ll a[n];
                ll sum = 0;
                for(ll i=0;i<n;i++){
                    cin>>a[i];
                    sum+=a[i];
                }
         
                if( k == 1){
                    cout<<max_sub_array(a,n)<<endl;
                    continue;
                }
                
         
                ll sum2 = max_sub_array(a,n);
                ll a1[n];
                ll maxx = a[n-1];
                a1[n-1] = a[n-1];
                for(ll i = n-2;i>=0;i--){
                    a1[i] = a1[i+1] + a[i];
                    if(a1[i]>maxx){
                        maxx = a1[i];
                    }
                }
                ll prefix = maxx;
                ll a2[n];
                ll maxx2 = a[0];
                a2[0] = a[0];
                for(ll i = 1;i<n;i++){
                    a2[i] = a2[i-1] + a[i];
                    if(a2[i]>maxx2){
                        maxx2 = a2[i];
                    }
                }
                ll suffix = maxx2;
                if(suffix + sum*(k-1) > sum2){
                    sum2 = suffix + sum*(k-1);
                }
                if(prefix + sum*(k-1) > sum2){
                    sum2 = prefix + sum*(k-1);
                }
                if(sum*k > sum2){
                    sum2 = sum*k;
                }
                if(prefix +suffix +sum*(k-2) > sum2 && k>1){
                    sum2 = prefix +suffix +sum*(k-2);
                }
                if(prefix + suffix > sum2){
                    sum2 = prefix + suffix;
                }
                cout<<sum2<<endl;
                
            }
        }    