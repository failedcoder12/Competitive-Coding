
// https://www.codechef.com/COOK86/problems/LIKECS05

	    #include <bits/stdc++.h>
	    using namespace std;
	    #define ll long long int
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
	     
	    vector<ll> multiply(vector<ll> a,vector<ll> b){
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
	        return result;
	    }
	    int main() {
	        ll n, q;
	        cin >> n >> q;
	     
	        vector<ll> col_r(n+1);
	        vector<ll> row_r(n+1);
	     
	        vector<ll> col_g(n+1);
	        vector<ll> row_g(n+1);
	     
	        vector<ll> tcol_g(n+1);
	        vector<ll> trow_g(n+1);
	     
	        for (ll i = 0; i <= n; i++) {
	            if(i == 0){
	                col_r[i] = 0;
	                row_r[i] = 0;
	                col_g[i] = 0;
	                row_g[i] = 0;
	                tcol_g[i] = 0;
	                trow_g[i] = 0;
	            }else {
	                col_r[i] = 1;
	                row_r[i] = 1;
	                col_g[i] = 1;
	                row_g[i] = 1;
	                tcol_g[i] = 1;
	                trow_g[i] = 1;
	            }
	        }
	     
	        set<ll> red_c;
	        set<ll> green_c;
	        set<ll> red_r;
	        set<ll> green_r;
	        set<ll> red_d;
	        set<ll> green_d;
	        set<ll> total_r;
	        set<ll> total_c;
	        set<ll> total_d;
	     
	        for (ll i = 0; i < q; i++) {
	            ll type, idx, color;
	            cin >> type >> idx >> color;
	     
	            if (type == 2) {
	                if (color == 0) {
	                    green_c.insert(idx);
	                    total_c.insert(idx);
	                } else {
	                    red_c.insert(idx);
	                    total_c.insert(idx);
	                }
	            }
	            if (type == 1) {
	                if (color == 0) {
	                    green_r.insert(idx);
	                    total_r.insert(idx);
	                } else {
	                    red_r.insert(idx);
	                    total_r.insert(idx);
	                }
	            }
	            if (type == 3) {
	                if (color == 0) {
	                    green_d.insert(idx);
	                    total_d.insert(idx);
	                } else {
	                    red_d.insert(idx);
	                    total_d.insert(idx);
	                }
	            }
	        }
	     
	        ll tc_n = 0, tr_c;
	        ll c_n = 0, r_n = 0;
	        for (auto x:red_c) {
	            c_n++;
	            col_r[x] = 0;
	        }
	        for (auto x:red_r) {
	            r_n++;
	            row_r[x] = 0;
	        }
	     
	     
	        vector<ll> mul_r = multiply(col_r,row_r);
	     
	        ll redd = (c_n + r_n)*n - (c_n*r_n);
	        for(auto p:red_d){
	            redd += mul_r[p];
	        }
	     
	        c_n = 0, r_n = 0;
	        for (auto x:green_c) {
	            c_n++;
	            col_g[x] = 0;
	        }
	        for (auto x:green_r) {
	            r_n++;
	            row_g[x] = 0;
	        }
	     
	        mul_r = multiply(col_g,row_g);
	     
	        ll greenn = (c_n + r_n)*n - (c_n*r_n);

			for(auto p:green_d){
	            greenn += mul_r[p];
	        }
	     
	        c_n = 0, r_n = 0;
	        for (auto x:total_c) {
	            c_n++;
	            tcol_g[x] = 0;
	        }
	        for (auto x:total_r) {
	            r_n++;
	            trow_g[x] = 0;
	        }
	     
	        mul_r = multiply(tcol_g,trow_g);
	     
	        ll totall = (c_n + r_n)*n - (c_n*r_n);
	        for(auto p:total_d){
	            totall += mul_r[p];
	        }
	     
	        ll yc,rc,gc,nc;
	        yc = redd + greenn - totall;
	        rc = redd - yc;
	        gc = greenn - yc;
	        nc = n*n - rc - yc - gc;
	     
	        cout<<nc<<" "<<rc<<" "<<gc<<" "<<yc<<endl;
	    } 


//Iterative
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll bitreverse(ll x,ll log2n){
    ll n=0;
    for(ll i=0;i<log2n;i++){
        n<<=1;
        n|=(x&1);
        x>>=1;
    }
    return n;
}

vector<complex<double> > fft(vector<complex<double> > a,bool inverse){
    ll n = a.size();
    ll log2n = log2(n);
    if(n<=1){
        return a;
    }
    vector<complex<double >>A;
    A.resize(n);
    for(ll i=0;i<n;i++){
        ll rev = bitreverse(i,log2n);
        A[i] = a[rev];
    }

    for(ll s=1;s<=log2n;s++){
        ll m = 1<<s;
        double ang = 2*M_PI/m*(inverse?-1:1);
        complex<double > w(1.0000), wn(cos(ang),sin(ang));
        for(ll j=0;j<m/2;j++){
            for(ll k=j;k<n;k+=m){
                complex<double> t= w*A[k+m/2];
                complex<double> u  = A[k];
                A[k] = u+t;
                A[k+m/2] = u-t;
            }
            w *= wn;
        }
    }
    if(inverse){
        for(ll i=0;i<n;i++){
            A[i] /= n ;
        }
    }
    return A;
}
vector<ll> multiply(vector<ll> a,vector<ll> b){
    vector<complex<double> >fa(a.begin(),a.end());
    vector<complex<double> >fb(b.begin(),b.end());
    ll n = 1;
    while(n<max(a.size(),b.size())){
        n <<= 1;
    }
    n<<=1;
    fa.resize(n);
    fb.resize(n);
    fa = fft(fa,false);
    fb = fft(fb,false);

    for(ll i=0;i<n;i++){
        fa[i] = fa[i]*fb[i];
    }

    fa = fft(fa,true);
    vector<ll> result(n);
    for(ll i=0;i<n;i++){
        result[i] = (ll)((fa[i].real())+0.5);
    }
    return result;
}
int main() {
    ll n, q;
    cin >> n >> q;

    vector<ll> col_r(n+1);
    vector<ll> row_r(n+1);

    vector<ll> col_g(n+1);
    vector<ll> row_g(n+1);

    vector<ll> tcol_g(n+1);
    vector<ll> trow_g(n+1);

    for (ll i = 0; i <= n; i++) {
        if(i == 0){
            col_r[i] = 0;
            row_r[i] = 0;
            col_g[i] = 0;
            row_g[i] = 0;
            tcol_g[i] = 0;
            trow_g[i] = 0;
        }else {
            col_r[i] = 1;
            row_r[i] = 1;
            col_g[i] = 1;
            row_g[i] = 1;
            tcol_g[i] = 1;
            trow_g[i] = 1;
        }
    }

    set<ll> red_c;
    set<ll> green_c;
    set<ll> red_r;
    set<ll> green_r;
    set<ll> red_d;
    set<ll> green_d;
    set<ll> total_r;
    set<ll> total_c;
    set<ll> total_d;

    for (ll i = 0; i < q; i++) {
        ll type, idx, color;
        cin >> type >> idx >> color;

        if (type == 2) {
            if (color == 0) {
                green_c.insert(idx);
                total_c.insert(idx);
            } else {
                red_c.insert(idx);
                total_c.insert(idx);
            }
        }
        if (type == 1) {
            if (color == 0) {
                green_r.insert(idx);
                total_r.insert(idx);
            } else {
                red_r.insert(idx);
                total_r.insert(idx);
            }
        }
        if (type == 3) {
            if (color == 0) {
                green_d.insert(idx);
                total_d.insert(idx);
            } else {
                red_d.insert(idx);
                total_d.insert(idx);
            }
        }
    }

    ll tc_n = 0, tr_c;
    ll c_n = 0, r_n = 0;
    for (auto x:red_c) {
        c_n++;
        col_r[x] = 0;
    }
    for (auto x:red_r) {
        r_n++;
        row_r[x] = 0;
    }


    vector<ll> mul_r = multiply(col_r,row_r);

    ll redd = (c_n + r_n)*n - (c_n*r_n);
    //    cout<<redd<<":";
    for(auto p:red_d){
        redd += mul_r[p];
    }

    // ooo

    c_n = 0, r_n = 0;
    for (auto x:green_c) {
        c_n++;
        col_g[x] = 0;
    }
    for (auto x:green_r) {
        r_n++;
        row_g[x] = 0;
    }

    mul_r = multiply(col_g,row_g);

    ll greenn = (c_n + r_n)*n - (c_n*r_n);
    //    cout<<greenn<<":";
    for(auto p:green_d){
        greenn += mul_r[p];
    }

    //0000

    c_n = 0, r_n = 0;
    for (auto x:total_c) {
        c_n++;
        tcol_g[x] = 0;
    }
    for (auto x:total_r) {
        r_n++;
        trow_g[x] = 0;
    }

    mul_r = multiply(tcol_g,trow_g);

    ll totall = (c_n + r_n)*n - (c_n*r_n);
    //    cout<<totall<<";";
    for(auto p:total_d){
        totall += mul_r[p];
    }

    // cout<<totall<<" "<<redd<<" "<<greenn<<endl;
    ll yc,rc,gc,nc;
    yc = redd + greenn - totall;
    rc = redd - yc;
    gc = greenn - yc;
    nc = n*n - rc - yc - gc;

    cout<<nc<<" "<<rc<<" "<<gc<<" "<<yc<<endl;
} 