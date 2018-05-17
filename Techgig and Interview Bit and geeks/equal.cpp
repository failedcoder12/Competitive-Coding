// https://www.interviewbit.com/problems/equal/

vector<int> Solution::equal(vector<int> &A) {
    
    int n = A.size();
    unordered_map<int,pair<int,int>> m;

    vector<int> ANS;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int s = A[i] + A[j];
            if(m.count(s)==0){
                m[s] = make_pair(i,j);
            }else {
                pair<int,int> pp = m[s];
                if(pp.first == i||pp.second == i||pp.first == j||pp.second == j){
                    continue;
                }
                vector<int> ans;
                ans.push_back(pp.first);
                ans.push_back(pp.second);
                ans.push_back(i);
                ans.push_back(j);
                if(ANS.size() == 0){
                    ANS = ans;
                }else {
                    bool rep = false;
                    for(int k=0;k<ANS.size();k++){
                        if(ANS[k] < ans[k]){
                            break;
                        }
                        if(ANS[k] > ans[k]){
                            rep = true;
                            break;
                        }
                    }
                    if(rep) {
                        ANS = ans;
                    }
                }
            }
        }
    }
    return ANS;
}
