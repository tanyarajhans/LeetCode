class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count=0;
     
        unordered_map<string,int> um;
        for(auto w:words) {
            um[w]++;
        }
        
     
        bool flag=false;
        for(auto x:words) {
            string wrd=x;
            reverse(wrd.begin(),wrd.end());
          
            if(wrd!=x && um[x]>0 && um[wrd]>0) {
                um[x]--;
                um[wrd]--;
                count+=4;
            }
            else if(wrd==x && um[x]>1) {
                um[x]-=2;
                count+=4;
            } 
            else if(wrd==x && !flag && um[x]>0) {
                um[x]--;
                count+=2;
                flag=true;
            }
        }
        return count;
    }
};