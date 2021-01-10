class Solution {
public:
 
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int swap=0,noswap=1;
        
        for(int i=1;i<n;i++){
            int x=INT_MAX, y=INT_MAX;
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                x=min(x, noswap);
                y=min(y, swap+1);
            }
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                x=min(x, swap);
                y=min(y, noswap+1);
            }
            swap=x;
            noswap=y;
        }
        return min(swap,noswap);
        
    }
};
