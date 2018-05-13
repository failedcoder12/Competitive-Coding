vector<int> Solution::lszero(vector<int> &A) {
    int sum = 0;
    unordered_map<int,int> m,mi;

    m[0] = -1;
    int ith,sumith = 0,length = 0;
    for(int i=0;i<A.size();i++){
        sum = sum+A[i];
        if(m.count(sum)==0) {
            m[sum] = i;
        }else {
            int ilength = i-m[sum];
            if(ilength > length){
                length = ilength;
                sumith = sum;
            }
        }
    }
    
    vector<int> ans;
    for(int i=m[sumith]+1;i<m[sumith]+length+1;i++){
        ans.push_back(A[i]);
    }

    return ans;

}
