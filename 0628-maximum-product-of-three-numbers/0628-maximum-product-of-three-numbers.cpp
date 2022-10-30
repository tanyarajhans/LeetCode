class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans;
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
	        int num = nums[i];
	  
	        if(num < min1)
	        {
	  	        min2=min1;
	  	        min1=num;
	        }
	        else if(num < min2)
	            min2=num;
        }
        for(int i=0;i<nums.size();i++)
        {
   	        int num = nums[i];
   	        if(num > max1) 
   	        {
   	            max3=max2;
	            max2=max1;
		        max1=num;			
            }
            else if(num > max2)
            {
      	        max3=max2;
      	        max2=num;
	        }
	        else if(num > max3)
	  	    max3=num;
        }
        return max(max2*max3*max1,min1*min2*max1);
    }
};