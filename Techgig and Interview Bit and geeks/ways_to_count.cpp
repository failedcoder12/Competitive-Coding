#define ll int
int Solution::numDecodings(string A) {
     ll n = A.length();
        
        if(A[0] == '0'){
            return 0;
        }
    
    ll count[n];
    count[0] = 1;
    count[1] = 1;

    for(ll i=2;i<=n;i++){
        count[i] = 0;
        if(A[i-1] > '0'){
            count[i] += count[i-1];
        }
        if(A[i-2] == '1'||(A[i-2] == '2' && A[i-1] < '7')){
            count[i] += count[i-2];
        }
    }
    return count[n];
}
