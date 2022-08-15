class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        int n=num;
        while(n>0){
            int p=n%10;
            v.push_back(p);
            n/=10;
        }
        vector<int>nums=v;
        int index=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==v[i]){
                continue;
            }
            else{
                index=i;
                break;
            }
        }
        int j;
        for(int i=index;i>=0;i--){
            if(v[i]==nums[index]){
                j=i;
            }
        }
        swap(v[j],v[index]);
        for(int i=0;i<v.size();i++){
            n+=pow(10,i)*v[i];
        }
        return n;
    }
};