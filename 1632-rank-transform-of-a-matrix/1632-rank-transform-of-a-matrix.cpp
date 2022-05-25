class Solution {
public:
    unordered_map<int,int> par;
    
    int find(int a){
        if(par[a]==a)
            return a;
        return par[a]=find(par[a]);
    }
    
    void merge(int a, int b){
        if(par.find(a)==par.end())
            par[a]=a;
        if(par.find(b)==par.end())
            par[b]=b;
        int x=find(a);
        int y=find(b);
        par[x]=y;
    }
    
    unordered_map<int, vector<int>> findGroups(){
        unordered_map<int, vector<int>> groups;
        for(auto it: par){
            groups[find(it.first)].push_back(it.first); //for same parent, adding all its children
        }
        return groups;
    }
    
    void reset(){
        par.clear();
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        map<int, vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[matrix[i][j]].push_back({i,j});
            }
        }
        vector<int> rank(n+m, 0);
        for(auto it: mp){
            reset();
            auto x=it.second; //all coordinates of same number
            for(int j=0;j<x.size();j++){
                merge(x[j].first, n+x[j].second); //merging row & col of a coord
            }
            for(auto t: findGroups()){ //all children of parent t.first
                int maxi=0;
                for(int i=0;i<t.second.size();i++) 
                    maxi=max(maxi, rank[t.second[i]]); //finding max rank
                for(int i=0;i<t.second.size();i++)
                    rank[t.second[i]]=maxi+1; //assigning all children as max+1
            }
            for(int j=0;j<x.size();j++){
                matrix[x[j].first][x[j].second]=rank[x[j].first];
            }
        }
        return matrix;
    }
};