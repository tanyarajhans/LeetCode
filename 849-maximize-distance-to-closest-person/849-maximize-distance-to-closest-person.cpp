class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int left[n];
        int right[n];
        left[0]=-1;
        right[n-1]=-1;
        if(seats[0]==1)
            left[0]=0;
        if(seats[n-1]==1)
            right[n-1]=n-1;
        for(int i=1;i<n;i++){
            if(seats[i]==1){
                left[i]=i;
            }
            else{
                left[i]=left[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(seats[i]==1){
                right[i]=i;
            }
            else{
                right[i]=right[i+1];
            }
        }
        int d=0;
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
            
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
            
        }
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                int x=INT_MAX, y=INT_MAX;
                if(left[i]!=-1){
                    x=i-left[i];
                }
                if(right[i]!=-1){
                    y=right[i]-i;
                }
                d=max(d,min(x,y));
            }
        }
        return d;
    }
};