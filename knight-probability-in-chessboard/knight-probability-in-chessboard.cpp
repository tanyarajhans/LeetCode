class Solution {
public:
   
    
    int dx[8]={-1,1,-1,1,2,-2,2,-2};
    int dy[8]={2,2,-2,-2,1,1,-1,-1};
    
    
    bool isValid(int i, int j, int n){
    if(i>n-1 || j>n-1 || i<0 || j<0 ){
       
        return false;
    }
    

    return true;
}
    
  
    
    
    double knightProbability(int N, int K, int r, int c) {
      
         vector<vector<vector<double>>> dp;
        for(int i=0; i<=K; i++)
            dp.push_back(vector<vector<double>>(N, vector<double>(N)));
        
        dp[0][r][c]=1.0;
        
        for(int i=1;i<=K;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    for(int l=0;l<8;l++){
                        int rr=j+dx[l];
                        int cc=k+dy[l];
                        if(isValid(rr,cc,N)){
                            dp[i][rr][cc]+=(dp[i-1][j][k])/8.0;
                        }
                    }
                }
            }
        }
        
        double ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans+=dp[K][i][j];
            }
        }
        return ans;
    }
};