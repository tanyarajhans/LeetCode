class Solution {
public:
    //VERY IMP: atleast one bar is fully included in the largest rectangle
    
    // If largest rectangle contains atleast one bar full then if we consideer largest of all areas containing every bar fully we get our answer
    
    //find nearest left bar with height < curr bar and do same for right.
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int l[n], r[n];
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty())
                l[i]=0;
            else{
                while(!s.empty() && h[s.top()]>=h[i])
                    s.pop();
                if(s.empty())
                    l[i]=0;
                else
                    l[i]=s.top()+1;
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
            if(s.empty())
                r[i]=n-1;
            else{
                while(!s.empty() && h[s.top()]>=h[i])
                    s.pop();
                if(s.empty())
                    r[i]=n-1;
                else
                    r[i]=s.top()-1;
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, h[i]*(r[i]-l[i]+1));
        }
        return ans;
    }
};