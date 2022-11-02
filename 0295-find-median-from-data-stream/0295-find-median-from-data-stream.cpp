class MedianFinder {
public:
    priority_queue<int> maxh; //lower half
    priority_queue<int, vector<int>, greater<int>> minh; //upper half
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh.empty() || maxh.top()>num)
            maxh.push(num);
        else
            minh.push(num);
        if(minh.size()>1+maxh.size()){
            int x=minh.top();
            minh.pop();
            maxh.push(x);
        }
        else if(maxh.size()>1+minh.size()){
            int x=maxh.top();
            maxh.pop();
            minh.push(x);
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