class Solution {
public:
    struct comp{
    bool operator()(vector<int> a, vector<int> b){
        return ((a[0] * a[0] + a[1] * a[1])>(b[0] * b[0] + b[1] * b[1])) ;
    }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<vector<int>,vector<vector<int>>, comp> pq;
        int n=points.size();
        
        for(int i=0;i<n;i++){
           pq.push(points[i]);
           
           
        }
         
        
        
        vector<vector<int>> t;
        
        for(int i=0;i<K;i++){
          t.push_back(pq.top());
          pq.pop();
            
        }
        return t;
    }
};
