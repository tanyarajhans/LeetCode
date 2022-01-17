class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        vector<pair<char, int>> c;
        vector<int> ind(n);
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u'){
                c.push_back({s[i], i});
                ind[i]=0; //vowel
            }
            else ind[i]=1;
        }
        int n1=c.size();
        if(n1==0)
            return n;
        if(n1==1){
            return max(c[0].second, n-c[0].second-1);
        }
        int ans=max(c[0].second, n-c.back().second -1); //considering only consonants
        for(int i=1;i<c.size();i++)
            ans=max(ans, c[i].second-c[i-1].second-1);
        for(int i=1;i<c.size();i++) //prefix xor of vowels
            c[i].first^=c[i-1].first;
        //calculating consonants before and after each vowel
        vector<int> left=ind, right=ind;
        for(int i=1;i<n;i++)
        {
            if(left[i]==1)
                left[i]+=left[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(right[i]==1)
                right[i]+=right[i+1];
        }
        // sotring each prefix XOR in map with corresponding vector of index
        map<int, vector<int >> mp;
        for(int i=0;i<c.size();i++)
        {
            mp[c[i].first].push_back(c[i].second);
        }
        for(auto it: mp){
            if(it.first==0){ //even vowels till here
                int in=it.second[it.second.size()-1];
                int x=in+1;
                if(in<n-1){
                    x+=right[in+1];
                }
                ans=max(ans, x);
            }
            else if(it.first!=0 && it.second.size()>1){
                int idx1 = it.second[0];
                int idx2 = it.second[it.second.size()-1];
                int x = (idx2-idx1);
                if(idx2<n-1)
                    x+=right[idx2+1];
                if(idx1>0)
                    x+=left[idx1];
                ans=max(ans, x);
            }
        }
        return ans;
    }
};