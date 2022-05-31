class Solution {
public:
    //new_hash = ((prev_hash << 1) & all_one) | last_digit_of_new_hash
    bool hasAllCodes(string s, int k) {
        // int n=s.size();
        // int i=0,j=0;
        // int x=1<<k;
        // set<string> st;
        // while(j<n){
        //     if(j-i+1==k){
        //         st.insert(s.substr(i,k));
        //         i++;
        //     }
        //     j++;
        // }
        // int d=st.size();
        // return (d==x);
        
        int x=1<<k;
        int n=s.size();
        vector<bool> v(x,false);
        int hash=0;
        int maxi=x-1;
        int c=0;
        for(int i=0;i<n;i++){
            hash=((hash<<1) & maxi) | (s[i]-'0');
            if(i-k+1>=0 && !v[hash]){
                v[hash]=true;
                c++;
                if(c==x)
                    return true;
            }
        }
        return (c==x);
    }
};