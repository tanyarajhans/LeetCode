class Solution {
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int M = A.size() ;
        int N = A[0].size();
        int l = A[0][0] ;          // low 
        int h = A[M-1][N-1];       // high 
        
        if( l == h )return l ;     // base case 
       
        int t = N*M - k ;          // looking for number of elements greater than me 
       
        while( l <= h )             // simple binary search 
        {
            int m = (l+h)/2 ; 
            
            int cnt = 0 ; 
            
            for( auto x : A )
            {
                cnt += x.end() - upper_bound( x.begin() , x.end() , m )  ;  
            }
            
            if( cnt <= t )h = m-1; 
            else l = m+1; 
        }
       
        return l;
    }
};