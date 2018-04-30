// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/


int SolveHist(vector<int> A){
    sort(A.begin(),A.end());
    stack<int> s;
    int i=0;
    int max_ans = 0;
    while(i<A.size()){
        if(s.empty() || A[s.top()]<=A[i]){
            s.push(i++);
        }else {
            int top = s.top();
            s.pop();
            if(!s.empty()) {
                max_ans = max(max_ans, A[top] * (i-s.top()-1));
            }else {
                max_ans = max(max_ans,A[top]*i);
            }
        }
    }
    int n = A.size();
    while(!s.empty()){
         int top = s.top();
            s.pop();
            if(!s.empty()) {
                max_ans = max(max_ans, A[top] * (n-s.top()-1));
            }else {
                max_ans = max(max_ans,A[top]*n);
            }
    }
    return max_ans;
}

int Solution::solve(vector<vector<int> > &A) {
    
     int maxx_ans = SolveHist(A[0]);
    for(int i=1;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(A[i][j]!=0){
                A[i][j] += A[i-1][j];
            }
        }
        maxx_ans = max(maxx_ans,SolveHist(A[i]));
    }
    return maxx_ans;
}
