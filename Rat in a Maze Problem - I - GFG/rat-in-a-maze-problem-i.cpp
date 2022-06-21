// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int vis[6][6];
    
    void solve(vector<vector<int>> &m, int n, string &temp, int x, int y){
        if(x<0 || y<0 || x>=n || y>=n || vis[x][y] || !m[x][y])
        return;
        if(x==n-1 && y==n-1){
            ans.push_back(temp);
            return;
        }
        vis[x][y]=1;
        temp.push_back('L');
        solve(m,n,temp,x,y-1);
        temp.pop_back();
        temp.push_back('R');
        solve(m,n,temp,x,y+1);
        temp.pop_back();
        temp.push_back('U');
        solve(m,n,temp,x-1,y);
        temp.pop_back();
        temp.push_back('D');
        solve(m,n,temp,x+1,y);
        temp.pop_back();
        vis[x][y]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string temp;
        memset(vis,0,sizeof(vis));
        solve(m,n,temp,0,0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends