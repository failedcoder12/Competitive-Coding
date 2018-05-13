int Solution::colorful(int A) {
   
    unordered_map<int,int> m;
    int x = A;
    
    if(A <= 9){
        return 1;
    }
    vector<int> l;
    while(x){
        l.push_back(x%10);
        if(m.count(x%10)!=0){
            return 0;
        }else {
            m[x%10] = 1;
        }
        x = x/10;
    }

    for(int i=0;i<l.size();i++){
        int pro = l[i];
        for(int j=i+1;j<l.size();j++){
            pro = pro * l[j];
            if(m.count(pro)!=0){
                return 0;
            } else {
                m[pro] = 1;
            }
        }
    }
    return 1;
}
