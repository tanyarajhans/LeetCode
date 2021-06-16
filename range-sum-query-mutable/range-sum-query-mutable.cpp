class NumArray {
public:
    int n;
    int st[1200005];
    
    void build(int si, int ss, int se, vector<int>& nums){
    if(ss==se){
        st[si]=nums[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si+1, ss, mid, nums);
    build(2*si+2, mid+1, se, nums);

    st[si]=st[2*si+1] + st[2*si+2];
    }
    
    
    int query(int si,int ss,int se,int qs,int qe)
    {

        if(qs<=ss && qe>=se)  
        {
            return st[si];
        }
        if(qs>se || qe<ss) 
            return 0;   

        int mid=(ss+se)/2;
        int left=query(2*si+1,ss,mid,qs,qe);
        int right=query(2*si+2,mid+1,se,qs,qe);
        return left+right;
    }
    
    void up(int si,int ss,int se,int qi, int val){
        if(ss==se){
            st[si]=val;
            return;
        }
        int mid=(ss+se)/2;
        if(qi<=mid)
            up(2*si+1,ss,mid,qi,val);
        else
            up(2*si+2,mid+1,se,qi,val);
        st[si]=st[2*si+1]+st[2*si+2];
    }
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        build(0,0,n-1, nums);
    }
    
    void update(int index, int val) {
        return up(0,0,n-1,index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */