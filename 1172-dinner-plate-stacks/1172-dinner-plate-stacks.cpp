class DinnerPlates {
public:
    set<int> notFull;
    vector<stack<int>> stacks;
    int cap;
    
    DinnerPlates(int capacity) {
        cap=capacity;
    }
    
    void push(int val) {
        if(notFull.empty()){
            stacks.push_back(stack<int>());
            notFull.insert(stacks.size()-1);
        }
        int ind=*notFull.begin();
            stacks[ind].push(val);
        if(stacks[ind].size()==cap){
            notFull.erase(ind);
        }
    }
    
    int pop() {
        if(stacks.empty())
            return -1;
        int v=stacks.size();
        int ans=stacks[v-1].top();
        stacks[v-1].pop(); //in case it becomes empty after popping
        while(stacks.size() && stacks.back().empty()){
            notFull.erase(stacks.size()-1);
            stacks.pop_back();
        }
        if(!stacks.empty() && stacks.back().size()<cap){
            notFull.insert(stacks.size()-1);
        }
        return ans;
    }
    
    int popAtStack(int index) {
        if(index>=stacks.size())
            return -1;
        if(stacks[index].empty()){
            return -1;
        }
        if(index==stacks.size()-1)
            return pop();
        
        int ans=stacks[index].top();
        stacks[index].pop();
        notFull.insert(index);
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */