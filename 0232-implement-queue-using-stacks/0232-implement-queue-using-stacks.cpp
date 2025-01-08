class MyQueue {
public:
    stack<int>stk;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
        
    }
    
    int pop() {
        stack<int>stk2;
        int dummy=0;
        while(!stk.empty()){
            dummy=stk.top();
            stk.pop();
            if(stk.empty()){
                break;
            }
            stk2.push(dummy);
        }
        while(!stk2.empty()){
            stk.push(stk2.top());
            stk2.pop();
        }

        return dummy;
        
    }
    
    int peek() {
        stack<int>stk2;
        int dummy=0;
        while(!stk.empty()){
            dummy=stk.top();
            stk.pop();
            stk2.push(dummy);
        }
        while(!stk2.empty()){
            stk.push(stk2.top());
            stk2.pop();
        }

        return dummy;
        
    }
    
    bool empty() {

        if(stk.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */