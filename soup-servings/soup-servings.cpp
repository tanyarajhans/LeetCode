class Solution {
public:
    vector<vector<double>> t;
    
    double solve(int a, int b){
        if(a<=0 && b<=0)
            return 0.50;
        if(a<=0 && b>0)
            return 1.0;
        if(a>0 && b<=0)
            return 0.0;
        if(t[a][b]!=-1)
            return t[a][b];
        return t[a][b]=0.25*(solve(a-100,b)+solve(a-75,b-25)+solve(a-50,b-50)+solve(a-25,b-75));
        
    }
    
    double soupServings(int n) {
        if(n>=5000)
            return 1.0;
        t.resize(n+1, vector<double>(n+1,-1));
        return solve(n,n);
    }
};