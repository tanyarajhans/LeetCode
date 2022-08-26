class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        string temp = "1";
        int i = 1;
        while(s.size() >= temp.size())
        {
            if(s == temp)
            {
                return true;
            }
            long long p = pow(2,i);
            temp = to_string(p);
            sort(temp.begin(),temp.end());
            i++;
        }
        return false;
    }
};