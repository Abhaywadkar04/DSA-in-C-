class CustomStack {
public:
    vector<int>s;
    int p;
    int i=-1;

    CustomStack(int maxSize) {
        p=maxSize;
        
    }
    
    void push(int x) {

        if(s.size()==p)return;
        s.push_back(x);
        i++;
        
    }
    
    int pop() {
        if(s.empty())return -1;
        int ans = s.back();
        s.pop_back();
        return ans;

        
    }
    
void increment(int k, int val) {
    for (int j = 0; j < min(k, (int)s.size()); j++) {
        s[j] += val;  
    }
}


        
    
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */