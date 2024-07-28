class MinStack {
public:
    std::stack<int> stk;
    std::stack<int> mstk;
    int min = std::numeric_limits<int>::max();
    MinStack() {

    }
    
    void push(int val) {
         stk.push(val);
        if(mstk.size() == 0 || mstk.top() >= val){
            mstk.push(val);
        } else {
            mstk.push(mstk.top());
        }
       
        // mstk.push(min);
    }
    
    void pop() {
        stk.pop();
        mstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */