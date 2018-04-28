// https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
        int dpr[A.size()];
        int dpl[A.size()];
        // cout<<A.size()<<"  ";
        for(int i=0;i<A.size();i++){
            dpl[i] = dpr[i] = 1;
        }

        for(int i=0;i<A.size();i++){
            for(int j=0;j<i;j++){
                if(A[i]>A[j]){
                    dpr[i] = max(dpr[i],dpr[j]+1);
                }
            }
            // cout<<dpr[i]<<" ";
        }
        // cout<<endl;
        vector<int> B(A.size());
        for(int i=0;i<A.size();i++){
            B[i] = A[A.size()-i-1];
            // cout<<B[i]<<","<<A[A.size()-i-1]<<" ";
        }
        // cout<<endl;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<i;j++){
                if(B[i]>B[j]){
                    dpl[i] = max(dpl[i],dpl[j]+1);
                }
            }
            // cout<<dpl[i]<<" ";
        }

        int maxans = 0;
        for(int i=0;i<A.size();i++){
            
            if(dpr[i] == 1){
                maxans = max(maxans,dpr[i]+dpl[A.size()-1-i]-1) ;
            }else if(dpl[i] == 1){
                maxans = max(maxans,dpr[i]+dpl[A.size()-1-i]-1) ;
            }else {
                maxans = max(maxans,dpr[i]+dpl[A.size()-1-i]-1) ;
            }            
        }
        return maxans;

}
