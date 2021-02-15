class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        bool f=true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                f=false;
                break;
            }
        }
        if(f==true)
            return arr;
        int n=arr.size();
        int x=-1;
        int p=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                x=i;
                break;
            }    
        }
        if(x==-1)
            return arr;
        int maxi=INT_MIN;
        for(int i=x+1;i<n;i++){
            if(arr[i]<arr[x] && arr[i]>maxi){
                maxi=arr[i];
                p=i;
            }    
        }
        swap(arr[x],arr[p]);
        return arr;
    }
};