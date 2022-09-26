class Solution {
public:
    int p[26];
    
    int find(int x){
        if(p[x]==x)
            return x;
        return p[x]=find(p[x]);
    }
    
    void merge(int x, int y){
        int p1=find(x);
        int p2=find(y);
        if(p1==p2)
            return;
        p[p1]=p2;
    }
    
    bool equationsPossible(vector<string>& eq) {
        for(int i=0;i<26;i++)
            p[i]=i;
        for(auto it: eq){
            int x=it[0]-'a';
            char c=it[1];
            int y=it[3]-'a';
            int p1=find(x);
            int p2=find(y);
            if(c=='=')
                merge(x,y);
        }
        for(auto it: eq){
            int x=it[0]-'a';
            char c=it[1];
            int y=it[3]-'a';
            int p1=find(x);
            int p2=find(y);
            if(c=='!'){
                if(p1==p2)
                    return false;
            }
        }
        
        return true;
    }
};