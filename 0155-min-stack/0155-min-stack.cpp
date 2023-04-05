class MinStack {
    stack<pair<long long,long long>> s;
    int minEle;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            minEle = val;
            s.push({val,minEle});
            return;
        }
        minEle = min(val,minEle);
        s.push({val,minEle});
    }
    
    void pop() {
        if(s.empty())return;
        s.pop();
        if(s.empty())return;
        minEle = s.top().second;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return minEle;
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