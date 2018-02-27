#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define hashmap unordered_map<string,bool>

//printing the puzzle
void print_puzzle(char puzzle[10][10]){
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            cout<<puzzle[i][j];
        }
        cout<<endl;
    }
};

// Copying all element of hashmap
hashmap copy_set(hashmap h){
    hashmap hcopy;
    for(auto hh:h){
        hcopy[hh.first] = hh.second;
    }
    return hcopy;
}

//Getting all empty or non - cell where it can be inserted on right direction
ll get_RHS_empty_cell_count(char puzzle[10][10],ll row,ll col){
    ll count = 0;
    while(col<10&&puzzle[row][col] != '+'){
        count++;
        col++;
    }
    return count;
}

//Getting all empty or non - cell where it can be inserted in down direction
ll get_down_empty_cell_count(char puzzle[10][10],ll row,ll col){
    ll count = 0;
    while(row<10 && puzzle[row][col] != '+'){
        count++;
        row++;
    }
    return count;
}

//From where that row start getting filled i.e. whether its empty or not but non + from right direction
ll get_up_start_row(char puzzle[10][10],ll row,ll col){
    while(row >=0 && puzzle[row][col]!='+'){
        row--;
    }
    return row+1;
}

//From where that row start getting filled i.e. whether its empty or not but non + from left direction
ll get_left_start_count(char puzzle[10][10],ll row,ll col){
    while(col >=0 && puzzle[row][col]!='+'){
        col--;
    }
    return col+1;
}

// Fitting the word in right direction
bool can_right_fit(char puzzle[10][10],ll row,ll col,string s){
    for(ll j=col;j<10 && j-col+1 <=s.length();j++){
        // checking whether it is -ve or it is equal to the char inserted
        if(puzzle[row][j] != '-' && puzzle[row][j] != s[j-col])
            return false;
    }
    return true;
}


// Fitting the word in down direction
bool can_down_fit(char puzzle[10][10],ll row,ll col,string s){
    for(ll i=row;i<10 && i-row+1 <=s.length();i++){
        // checking whether it is - or it is equal to the char inserted
        if(puzzle[i][col] != '-' && puzzle[i][col] != s[i-row])
            return false;
    }
    return true;
}

//putting all values in right direction
void fitting_in_right(char puzzle[10][10],ll row,ll col,string s){
    for(ll j = col;j<10 && j-col+1 <=s.length();j++){
        puzzle[row][j] = s[j-col];
    }
}

//putting all values in down direction
void fitting_in_down(char puzzle[10][10],ll row,ll col,string s){
    for(ll i=row;i<10 && i-row+1 <=s.length();i++){
        puzzle[i][col] = s[i-row];
    }
}

//after filling a word finding the next cell where char can be inserted and then recursive calling
pair<ll,ll> get_next_cell(char puzzle[10][10],ll row,ll col){
    for(ll i=row;i<10;i++){
        for(ll j=0;j<10;j++){
            //checking for first col on right side or below that row
            if(i == row && j>=col && puzzle[i][j] == '-')
                return make_pair(i,j);
            else if(i>row && puzzle[i][j] == '-')
                return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
};

// the main puzzle solver
void complete_the_puzzle_helper(char puzzle[10][10],hashmap h,ll row,ll col){
    if(puzzle[row][col] == '-'){
        //calculating number of empty cells in right
        ll right_count = get_RHS_empty_cell_count(puzzle,row,col);

        //calculating number of empty or non + cells in left
        ll left_start = get_left_start_count(puzzle,row,col);
        
        //length of string which can be fitted at this point
        ll string_to_be_fitted_length;
        if(left_start == col){
            string_to_be_fitted_length = right_count;
        }else {
            string_to_be_fitted_length = right_count+(col-left_start);
        }

        //string length if less than 1 then it should be placed down instead right
        if(string_to_be_fitted_length > 1){
            for(auto s:h){
                if(s.second){
                    string fs = s.first;
                    
                    //checking if it can be fitted
                    if(fs.length() == string_to_be_fitted_length && can_right_fit(puzzle,row,left_start,fs)){
                        
                        //creating copy of puzzle for recursion
                        char puzzlecopy[10][10];
                        for(ll i=0;i<10;i++){
                            for(ll j=0;j<10;j++){
                                puzzlecopy[i][j] = puzzle[i][j];
                            }
                        }
                        
                        //copy of hashmap for recursion
                        hashmap hcopy = copy_set(h);
                        
                        //now fs string is fitted so making it false
                        hcopy[fs] = false;
                        
                        //fitting it
                        fitting_in_right(puzzlecopy,row,left_start,fs);
                        
                        //getting next empty cell
                        pair<ll,ll> p = get_next_cell(puzzlecopy,row,col);
                        if(p.first == -1){
                            
                            //if all filled print it
                            print_puzzle(puzzlecopy);
                        }else {
                            
                            //recursive call
                            complete_the_puzzle_helper(puzzlecopy,hcopy,p.first,p.second);
                        }
                    }
                }
            }
        }else {
            
            //calculating number of empty cells down
            ll down_count = get_down_empty_cell_count(puzzle,row,col);

            //calculating number of empty or non + cells above
            ll up_start = get_up_start_row(puzzle,row,col);

            //length of string which can be fitted at this point
            ll string_to_be_fitted_length2;
            if(up_start == row){
                string_to_be_fitted_length2 = down_count;
            }else {
                string_to_be_fitted_length2 = down_count+(row-up_start);
            }
            for(auto s:h){
                if(s.second){
                    string fs = s.first;
                    
                    //checking if it can be fitted
                    if(fs.length() == string_to_be_fitted_length2 && can_down_fit(puzzle,up_start,col,fs)){

                        //creating copy of puzzle for recursion
                        char puzzlecopy[10][10];
                        for(ll i=0;i<10;i++){
                            for(ll j=0;j<10;j++){
                                puzzlecopy[i][j] = puzzle[i][j];
                            }
                        }
                        
                        //copy of hashmap for recursion
                        hashmap hcopy = copy_set(h);
                        
                        //now fs string is fitted so making it false
                        hcopy[fs] = false;
                        
                        //fitting it
                        fitting_in_down(puzzlecopy,up_start,col,fs);
                        
                        //getting next position
                        pair<ll,ll> p = get_next_cell(puzzlecopy,row,col);
                        if(p.first == -1){
                            //if all done print it
                            print_puzzle(puzzlecopy);
                        }else {
                            
                            //recursive call
                            complete_the_puzzle_helper(puzzlecopy,hcopy,p.first,p.second);
                        }
                    }
                }
            }
        }
    }
}

// Finding out first position where string can be inserted
void complete_the_puzzle(char puzzle[10][10],hashmap h){
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            if(puzzle[i][j] == '-'){
                //finding first -
                complete_the_puzzle_helper(puzzle,h,i,j);
                return;
            }
        }
    }
};


int main(){
    char puzzle[10][10];

    //Scanning '+' and '-' matrix
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            cin>>puzzle[i][j];
        }
    }
    string s;
    cin>>s;

    //adding all strings to a hashmap
    ll j=0,k=0;
    hashmap h;
    string ss = "";
    
    //way to take input and putiing it in hashmap
    for(ll i=0;i<s.length();i++){
        if(s[i]==';'){
            h[ss] = true;
            ss="";
        }else{
            ss+=s[i];
        }
    }
    h[ss] = true;

    //Calling function
    complete_the_puzzle(puzzle,h);
}


















