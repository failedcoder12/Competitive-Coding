// http://www.spoj.com/problems/VFMUL/

    #include <bits/stdc++.h>
    using namespace std;
    #define ll int
     
    vector< complex<double> > fft(vector< complex<double> > a){
        ll n = a.size();
        if(n<=1){
            return a;
        }
        vector< complex<double> > a0(n/2) , a1(n/2);
     
        for(ll i=0;i<n/2;i++){
            a0[i] = a[2*i];
            a1[i] = a[2*i + 1];
        }
     
        a0 = fft(a0);
        a1 = fft(a1);
     
        double ang = 2*M_PI/n;
        complex<double > w(1.0000) , wn(cos(ang),sin(ang));
     
        for(ll i=0;i<n/2;i++){
            a[i] = a0[i] + w*a1[i];
            a[i+n/2] = a0[i] - w*a1[i];
            w = w*wn;
        }
     
        return a;
    }
     
     
    vector< complex<double> > inv_fft(vector< complex<double> > y){
        ll n = y.size();
     
        if(n<=1){
            return y;
        }
     
        vector< complex<double> > y0(n/2) , y1(n/2);
     
        for(ll i=0;i<n/2;i++){
            y0[i] = y[2*i];
            y1[i] = y[2*i + 1];
        }
     
        y0 = inv_fft(y0);
        y1 = inv_fft(y1);
     
        double ang = 2*M_PI/n *-1;
        complex<double > w(1.0000) , wn(cos(ang),sin(ang));
     
        for(ll i=0;i<n/2;i++){
            y[i] = y0[i] + w*y1[i] ;
            y[i+n/2] = y0[i] - w*y1[i];
     
            y[i] /= 2;
            y[i+n/2] /= 2;
     
            w = w*wn;
        }
     
        return y;
    }
     
    void multiply(vector<ll> a,vector<ll> b){
        vector<complex<double > >fa(a.begin(),a.end());
        vector<complex<double > >fb(b.begin(),b.end());
     
        ll n = 1;
        while(n< max(a.size(),b.size())){
            n <<= 1;
        }
        n <<= 1;
        fa.resize(n);
        fb.resize(n);
     
        fa = fft(fa);
        fb = fft(fb);
     
        for(ll i=0;i<n;i++){
            fa[i] = fa[i] * fb[i];
        }
     
        fa = inv_fft(fa);
     
        vector<ll> result(n);
        for(ll i=0;i<n;i++){
            result[i] = (ll)((fa[i].real())+0.5);
        }
     
        ll carry = 0;
        for(ll i=0;i<n;i++){
            result[i] = result[i] + carry;
            carry = result[i]/10;
            result[i] = result[i]%10;
        }
     
        bool flag = 0;
        for(ll i = n-1;i>=0;i--){
            if(result[i]||flag){
                cout<<result[i];
                flag = 1;
            }
        }
        if(!flag){
            cout<<0;
        }
        cout<<endl;
    }
     
    int main(){
        ll t;
        cin>>t;
        while(t--){
            string a,b;
            cin>>a>>b;
            vector<ll> a_v,b_v;
            for(ll i=0;i<a.length();i++){
                a_v.push_back((ll)(a[i]-'0'));
            }
            for(ll i=0;i<b.length();i++){
                b_v.push_back((ll)(b[i]-'0'));
            }
     
            reverse(a_v.begin(),a_v.end());
            reverse(b_v.begin(),b_v.end());
            multiply(a_v,b_v);
        }
    } 