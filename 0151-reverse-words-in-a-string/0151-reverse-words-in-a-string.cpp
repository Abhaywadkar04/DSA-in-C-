class Solution {
public:
    string reverseWords(string s) {

        stack<string>stk;
        string n;
        string word;
        stringstream ss(s);

        while(ss>>word){
            stk.push(word);
        }
        

     while (!stk.empty()) {
    n += stk.top();  
    stk.pop();      
    if (!stk.empty()) {
        n += " ";   
    }
}


        

        return n;




        
    }
};