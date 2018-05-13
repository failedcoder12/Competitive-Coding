#include <list>
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,list<int>> m;

    for(int i=0;i<A.size();i++){
        m[A[i]].push_back(i);
    }

    int mini = INT_MAX;

    for(int i=0;i<A.size();i++){
        if(m.count(A[i]) && m.count(B-A[i])){
            
            if(max(m[A[i]].front(),m[B-A[i]].front())<mini) {
                
                if((m[A[i]].front()==m[B-A[i]].front()) && m[A[i]].size() < 2){
                    continue;
                }
                if((m[A[i]].front()==m[B-A[i]].front())&& m[A[i]].size() >= 2){
                    //cout<<"P"<<m[A[i]].size();
            
                    int temp = m[A[i]].front(); 
                    m[A[i]].pop_front();
                    if(max(m[A[i]].front(),temp) >= mini){
                    m[A[i]].push_front(temp);
                    continue;
                    }
                    if(max(m[A[i]].front(),temp) < mini)
                        mini = max(m[A[i]].front(),temp);
                    m[A[i]].push_front(temp);
                    //cout<<m[A[i]].front()<<" "<<m[B-A[i]].front()<<" "<<mini<<"->";

                }else 
                mini = max(m[A[i]].front(), m[B - A[i]].front());
            }
        }
    }

    vector<int> ans;

    if(mini < A.size()){
        
        ans.push_back(m[B-A[mini]].front()+1);
        m[B-A[mini]].pop_front();
        ans.push_back(m[A[mini]].front()+1);
    }
    return ans;
}
