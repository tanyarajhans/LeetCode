class Solution {
   
    class TrieNode {
        public:
        TrieNode* child[2];
        TrieNode (){
            child[0]=NULL;
            child[1]=NULL;
        };
    };
    TrieNode* build(vector<int>& nums){
        int n=nums.size();
        TrieNode* root=new TrieNode();
        TrieNode* temp;
        for(int i=0;i<n;i++){
            temp=root;
            for(int j=31;j>=0;j--){
                int k = (nums[i]>>j) & 1;
                if(temp->child[k]==NULL)
                    temp->child[k]=new TrieNode();
                temp=temp->child[k];
            }
        }
        return root;
    }
    int dfs(TrieNode* root, int x, int maxl, int ans, int bit){
        if(ans>maxl)
            return -1;
        if(bit==-1)
            return x^ans;
        int bitt= (x >> bit) & 1;
        if(root->child[1-bitt]!=NULL){
            int v=dfs(root->child[1-bitt], x, maxl, (ans | (1-bitt) << bit), bit-1);
            if(v>=0)
                return v;
        }
        if(root->child[bitt]!=NULL){
            int v=dfs(root->child[bitt], x, maxl, (ans | (bitt) << bit), bit-1);
            if(v>=0)
                return v;
        }
        return -1;   
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> ans;
        TrieNode* root=build(nums);
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int m=queries[i][1];
            int k=dfs(root,x,m,0,31);
            ans.push_back(k);
        }
        return ans;
    }
};