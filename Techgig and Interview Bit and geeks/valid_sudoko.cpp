// https://www.interviewbit.com/problems/valid-sudoku/

#define ll long long int

int Solution::isValidSudoku(const vector<string> &A) {
    for(auto x:A){
        unordered_map<char,ll> h;
        for(ll i=0;i<x.length();i++){
            if(x[i] == '.'){
                continue;
            }
            if(h.count(x[i]) !=0 ){
                // cout<<"P1";
                return 0;
            }else {
                h[x[i]] = 1;
            }
        }
    }

    unordered_map<char,ll> p[9];
    for(ll i=0;i<A.size();i++){
        for(ll j=0;j<A[i].length();j++){
            if(A[i][j] == '.'){
                continue;
            }
            if(p[j].count(A[i][j]) !=0 ){
                // cout<<"P2";
                return 0;
            }else {
                p[j][A[i][j]] = 1;
            }
        }
    }
    
    set<char> m[3][3];
    vector<char> mc[3][3];
    for(ll i=0;i<A.size();i++){
        for(ll j=0;j<A.size();j++){
            // cout<<A[i][j]<<" ";
            if(A[i][j] == '.'){
                continue;
            }
            m[i/3][j/3].insert(A[i][j]);
            mc[i/3][j/3].push_back(A[i][j]);
        }
        // cout<<endl;
    }
    
    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            if(m[i][j].size() != mc[i][j].size()){
                // cout<<"P3";
                return 0;
            }
        }
    }
    return 1;
    
}
