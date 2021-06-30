class MinStack {
public:
    /** initialize your data structure here. */
    long long int minele=INT_MAX;
    stack<long long int> s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minele=val;
        }
        else if(val<minele){
            long long int t=val;
            t=2*t-minele;
            s.push(t);
            minele=val;
        }
        else
            s.push(val);
    }
    
    void pop() {
        if(s.top()<minele){
            long long int k=s.top();
            minele=2*minele-k;
        }
        s.pop();
        if(s.empty())
            minele=INT_MAX;
    }
    
    int top() {
        if(s.top()<minele)
            return minele;
        return s.top();
    }
    
    int getMin() {
        return minele;
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