// https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B) {
    
    unordered_map<int,int> m;
    if(B == 0){
        for(int i=0;i<A.size();i++){
            if(m.count(A[i])!=0){
                return 1;
            }
           m[A[i]]=i;
        }    
        return 0;
    }
    for(int i=0;i<A.size();i++){
        m[A[i]]=i;
    }

    for(int i=0;i<A.size();i++){
        if(m.count(A[i]) && m.count(B+A[i])){
            if(m[A[i]] == m[B+A[i]]){
                continue;
            }
            return 1;
        }
    }
    return 0;
}
