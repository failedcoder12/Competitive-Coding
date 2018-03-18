// https://www.hackerearth.com/challenge/competitive/airtel-crack-the-code/algorithm/odd-even-subarrays-72ad69db/

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    int main(){
        ll n;
        cin>>n;
        ll a[n];
        ll total = 0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            a[i] = a[i]%2;
            if(a[i] == 0){
                a[i] = -1;
            }
            total += a[i];
        }
     
        unordered_map<ll,ll> um;
        ll cur = 0;
        for(ll i=0;i<n;i++){
            cur+=a[i];
            um[cur]++;
        }
        ll count = 0;
        for(auto x:um){
            if(x.second > 1){
                count+= (x.second)*(x.second-1)/2;
            }
        }
        if(um.find(0)!=um.end()){
            count+=um[0];
        }
        cout<<count<<endl;
    }