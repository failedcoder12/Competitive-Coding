// https://www.codechef.com/APRIL18B/problems/GOODPREF

    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
     
     
    int main(){
        ll t;
        cin>>t;
        while(t--){
            string s;
            cin>>s;
            ll n;
            cin>>n;
            ll prefixa[1001];
            ll prefixb[1001];
            ll ca = 0;
            ll cb = 0;
            ll count = 0;
            for(ll i=0;i<s.length();i++){
                if(s[i] == 'a'){
                    ca++;
                }if(s[i] == 'b'){
                    cb++;
                }
                if(ca>cb){
                    count++;
                }
            }
            if(ca == cb){
                cout<<count*n<<endl;
                continue;
            }
            ca = cb = count = 0;
            ll loop = s.length()*s.length();
            if(n<s.length()){
                loop = n*s.length();
            }
            for(ll i=0;i<loop;i++){
                if(s[i%s.length()]=='a'){
                    ca++;
                } else{
                    cb++;
                }
                if(ca>cb){
                    count++;
                }
                // cout<<ca<<"->"<<cb<<"->>"<<count<<":";
            }
            if(ca>cb) {
                if (loop == n * s.length()) {
                    cout << count << endl;
                    continue;
                } else {
                    count += (n* s.length() - loop) ;
                    cout << count << endl;
                    continue;
                }
            }else {
                cout<<count<<endl;
            }
        }
    } 