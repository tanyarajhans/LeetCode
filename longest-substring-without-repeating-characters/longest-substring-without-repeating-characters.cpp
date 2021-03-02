class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
	    int n=s.size();
	    map<char, int> m;
	    int ans=0;
	    while(j<n){
	        m[s[j]]++;
	        if(m.size()>j-i+1)
	        j++;
	        else if(m.size()==j-i+1){
	            ans=max(ans,j-i+1);
	            j++;
	        }
	        else{
	            while(m.size()<j-i+1){
	                m[s[i]]--;
	                if(m[s[i]]==0)
	                  m.erase(s[i]);
	                i++;
	            }
	            j++;
	        }
	    }
	    
	    return ans;
	    
    }
};