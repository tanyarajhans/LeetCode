class Solution {
public:
    string intToRoman(int num) {
        string ans;
        string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0 && i < 13; i++)
        {
            while(num >= n[i])
            {
                num -= n[i];
                ans += s[i];
            }
        }
        
        return ans;
    }
};