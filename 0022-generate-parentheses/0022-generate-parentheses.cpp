class Solution {
public:
vector<string>list;
void creator(string s,int open,int close,int n,vector<string>&list)
        {

            if(s.length()==2*n){
                list.push_back(s);
                return;
            }

            if(open<n){
                creator(s +"(",open+1,close,n,list);
            }
            if(close<open){
                creator(s+")",open,close+1,n,list);
            }
        }
    vector<string> generateParenthesis(int n) {



        creator("",0,0,n,list);

        return list;
        
    }
};