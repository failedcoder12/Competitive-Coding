
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
   
    set<vector<int>> ans;

    sort(A.begin(),A.end());

    int l,r;
    int n = A.size();
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            l = j+1;
            r = n-1;

            while(l<r){
                if(A[i]+A[j]+A[l]+A[r] == B){
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[l]);
                    temp.push_back(A[r]);
                    l++;
                    r--;
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }else if(A[i]+A[j]+A[l]+A[r] < B){
                    l++;
                }else {
                    r--;
                }
            }
        }
    }
    //sort(ans.begin(),ans.end());
    vector<vector<int>> aa;
    for(auto i:ans){
        aa.push_back(i);
    }
    return aa;}
