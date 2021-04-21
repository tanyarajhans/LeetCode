class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>a;
        a=triangle;
        int n=triangle.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                int x=INT_MAX,y=-1;
                if(i-1>=0&&j<a[i-1].size())
                {
                    x=a[i-1][j];
                }
                if(i-1>=0&&j-1>=0)
                {
                    x=min(x,a[i-1][j-1]);
                }
                if(x!=INT_MAX)
                    a[i][j]+=x;
            }
        }
        int min=INT_MAX;
        for(int i=0;i<a.size();i++)
        {
            if(a[a.size()-1][i]<min)
                min=a[a.size()-1][i];
        }
        return min;
    }
};