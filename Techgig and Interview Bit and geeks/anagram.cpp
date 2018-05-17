// https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    vector<string> B = A;
    unordered_map<string,vector<int>> m;

    for(int i=0;i<B.size();i++){
        sort(B[i].begin(),B[i].end());
        m[B[i]].push_back(i+1);
    }

    vector<vector<int>> ans;
    
    for(auto x:m){
        sort(x.second.begin(),x.second.end());
        ans.push_back(x.second);
    }
    return ans;
}
