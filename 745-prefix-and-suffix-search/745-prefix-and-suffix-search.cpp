class WordFilter {
public:
    class Trie{
        public:
        Trie* child[27]={NULL}; //27 bc of '{'
        int ind;
    };
    
    Trie *p;
    WordFilter(vector<string>& words) {
        p=new Trie();
        int n=words.size();
        for(int i=0;i<n;i++){
            string x="{"+words[i];
            for(int j=words[i].size()-1;j>=0;j--){
                x=words[i][j]+x;
                insert(p,x,i);
            }
            
        }
        
    }
    
    void insert(Trie* x, string &s, int in){
        Trie* curr=x;
        for(auto &c: s){
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new Trie();
            }
            curr=curr->child[c-'a'];
            curr->ind=in;
        }
    }
    
    int find(Trie* x, string &s){
        Trie* curr=x;
        for(auto &c: s){
            curr=curr->child[c-'a'];
            if(curr==NULL)
                return -1;
        }
        return curr->ind;
    }
    
    int f(string prefix, string suffix) {
        string st=suffix+"{"+prefix;
        return find(p, st);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */