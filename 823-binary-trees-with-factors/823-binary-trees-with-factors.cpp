class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long int> m;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            m[arr[i]]=1;
         }
      
      for(int i=1;i<n;i++){
        long long int count=0;
        for(int j=0;j<i;j++){
          if(arr[i]%arr[j]==0){
            if(m.find(arr[i]/arr[j])!=m.end()){
              count+=m.find(arr[j])->second*m.find(arr[i]/arr[j])->second;
            }
          }
        }
        m.find(arr[i])->second+=count;
      }
      
      long long int sum=0;
      for(auto it:m){
        sum+=it.second;
      }
      
      return sum%1000000007;
    }
};