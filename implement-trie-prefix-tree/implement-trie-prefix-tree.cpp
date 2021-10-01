class Trie {
public:
    struct Node{
        Node* arr[26];
        bool isEnd=false;
    };
    
    Node* root=new Node();
    
    Trie() {
        
    }
    
    void insert(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(temp->arr[ch-'a']==NULL){
                Node* newNode = new Node();
                temp->arr[ch-'a']=newNode;
            }
            temp=temp->arr[ch-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(temp->arr[ch-'a']==NULL)
                return false;
            temp=temp->arr[ch-'a'];
        }
        return (temp->isEnd==true);
    }
    
    bool startsWith(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(temp->arr[ch-'a']==NULL)
                return false;
            temp=temp->arr[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */