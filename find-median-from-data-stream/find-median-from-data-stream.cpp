class MedianFinder {

    /** initialize your data structure here. */
     public:  
      priority_queue<int> maxh; //max heap - smaller half
        priority_queue<int, vector<int>, greater<int>> minh; //min heap - greater half
    MedianFinder() {
      
        
    }
 
    void addNum(int num) {
        if(maxh.empty() || maxh.top()>num)
        maxh.push(num);
        else
        minh.push(num);
        if(minh.size()+1<maxh.size()){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size()+1<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size())
            return maxh.empty()?0:((double) maxh.top() + minh.top()) * 0.5;
        return (maxh.size() > minh.size())? maxh.top() : minh.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */