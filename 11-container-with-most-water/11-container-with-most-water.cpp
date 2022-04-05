class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=INT_MIN;
        while(l<r)
        {
            int h = min(height[l],height[r]);
            int w = r-l;
            area=max(area,h*w);
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};