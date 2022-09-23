class Solution {
public:
    int concatenatedBinary(int n) {
        int ans=0;
        int mod=1e9+7;
        
        for(int num=1;num<=n;num++)
        {
            bool flag=false;
            
            for(int i=31;i>=0;i--)
            {
                if((num&(1<<i))!=0)
                {
                    flag=true;
                }
            
                if(flag)
                {
                    if(((1<<i)&num)==0)
                    {
                        ans=(((long)ans*2)%mod + 0)%mod;
                    }
                    else
                    {
                        ans=(((long)ans*2)%mod + 1)%mod;
                    }
                }
            }
        }
        
        return ans%mod;
    }
};