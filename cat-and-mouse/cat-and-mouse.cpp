class Solution {
public:
    int n,m;
    int dp[104][52][52]; //turns, mouse, cat
    //let's indicate draw as 0, mouse's win as 1 and cat's win as 2.
    int solve(int turns, int m, int c, vector<vector<int>>& graph){
        if(turns==2*n)
            return 0;
        if(c==m)
            return dp[turns][m][c]=2;
        if(m==0)
            return dp[turns][m][c]=1;
        if(dp[turns][m][c]!=-1)
            return dp[turns][m][c];
        int x=turns%2;
        int ans=0;
        if(x==0){ //mouse
            ans=true; //cat's win
            for(int i=0;i<graph[m].size();i++){
                int nextTurn=solve(turns+1, graph[m][i], c, graph);
                if(nextTurn==1)
                {
                    return dp[turns][m][c]=1;
                }
                else if(nextTurn!=2){
                    ans=false;
                } 
            }
            if(ans)
                return dp[turns][m][c]=2;
            return dp[turns][m][c]=0;
        }
        else{
            ans=true; //mouse's win
            for(int i=0;i<graph[c].size();i++){
                if(graph[c][i]!=0){
                    int nextTurn=solve(turns+1, m, graph[c][i], graph);
                    if(nextTurn==2){
                        return dp[turns][m][c]=2;
                    }
                    else if(nextTurn!=1){
                        ans=false;
                    }
                }
            }
            if(ans)
                return dp[turns][m][c]=1;
            return dp[turns][m][c]=0;
        }
        return dp[turns][m][c]=0;
    }
    
    int catMouseGame(vector<vector<int>>& graph) {
        n=graph.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,2,graph);
    }
};