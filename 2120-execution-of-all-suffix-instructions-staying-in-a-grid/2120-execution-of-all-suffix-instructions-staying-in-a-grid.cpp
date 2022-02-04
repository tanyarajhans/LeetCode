class Solution {
public:
    
    
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> v;
        for(int i=0; i<s.length(); i++){
            int j = i;
            int row = startPos[0];
            int col = startPos[1];
            while(j<s.length()){
                if(s[j] == 'R') col += 1;
                else if(s[j] == 'L') col -= 1;
                else if(s[j] == 'D') row += 1;
                else row -= 1;
                if(row<0 || col<0 || row>=n || col>=n) break;
                j++;
            }
            v.push_back(j-i);
        }
        
        return v;
    }
};