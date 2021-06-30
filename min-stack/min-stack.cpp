class MinStack {
public:
    /** initialize your data structure here. */
    long long int minele=INT_MAX;
    stack<long long int> s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(0);
            minele=val;
        }
        else{
            s.push((long long int)val-minele);
            if(val<minele)
                minele=val;
        }
            
    }
    
    void pop() {
        long long int k=s.top();
        if(k<0){
            minele=minele-k;
        }
        s.pop();
    }
    
    int top() {
        long long int k=s.top();
        if(k<0){
            return minele;
        }
        else{
            return minele+k;
        }
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