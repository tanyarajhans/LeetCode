class Solution {
public:
    bool isPal(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    bool solve(string a, string b){
        int i=0, j=a.size()-1;
        while(i<j && a[i]==b[j]){
            i++,j--;
        }
        return (isPal(a, i, j) || isPal(b,i,j));
    }
    
    bool checkPalindromeFormation(string a, string b) {
       return (solve(a,b) || solve(b,a));
    }
};