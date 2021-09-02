class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if(n==0)
            return false;
        preorder+=',';
        n++;
        int ind=0;
        int cap=1;
        for(ind=0;ind<n;ind++){
            if(preorder[ind]!=',')
                continue;
            cap--;
            if(cap<0)
                return false;
            if(preorder[ind-1]!='#')
                cap+=2;
        }
        return (cap==0);
    }
};