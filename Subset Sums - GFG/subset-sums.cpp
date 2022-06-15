// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
int n;
vector<int> ans;

    void backtrack(int pos, vector<int> &arr, vector<int> &temp){
        if(pos==n)
            {
                int s=0;
                for(int i=0;i<temp.size();i++)
                    s+=temp[i];
                ans.push_back(s);
                return;
            }
           
        temp.push_back(arr[pos]);
        backtrack(pos+1, arr, temp);
        temp.pop_back();
        backtrack(pos+1, arr, temp);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        n=N;
        vector<int> temp;
        int pos=0;
        backtrack(pos, arr, temp);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends