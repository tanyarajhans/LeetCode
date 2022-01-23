class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        string s1=to_string(low);
        string s2=to_string(high);
        int s,e;
        
        int n1=s1.size();
        int n2=s2.size();
        
        for(int i=1;i<=9;i++){ //length of numbers
            int x=0;
            for(int j=i;j<=9;j++){
                x=x*10+j;
                if(x>=low && x<=high)
                    ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};