struct TrieNode{
        TrieNode* child[26];
        int sum;
        TrieNode(){
            sum=0;
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
    };

class MapSum {
public:
    /** Initialize your data structure here. */
    
    unordered_map<string, int> m;
    TrieNode* root;
    
    MapSum() {
        root=new TrieNode();
    }
    
    void insert(string key, int val) {
        int diff=val-m[key];
        TrieNode* curr=root;
        for(char ch: key){
            ch-='a';
            if(curr->child[ch]==NULL)
                curr->child[ch]=new TrieNode();
            curr=curr->child[ch];
            curr->sum+=diff;
        }
        m[key]=val;
    }
    
    int sum(string prefix) {
        TrieNode* curr=root;
        for(char ch: prefix){
            ch-='a';
            if(curr->child[ch]==NULL)
                return 0;
            curr=curr->child[ch];
        }
        return curr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */