class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int i=1,j=n;
        while(i<=j){
            if(k-->0){
                if(k%2==0)
                    ans.push_back(i++);
                else
                    ans.push_back(j--);
            }
            else
                ans.push_back(i++);
        }
        return ans;
    }
};