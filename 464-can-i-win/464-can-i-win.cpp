class Solution {
public:
    /*
        binary state represents available numbers to choose
        
        define f(state) as: it's current user's turn, if there exists a choice so that f(next state) = false (lose). If so, f(state) = true (win)
    */
    vector<int> f;
    int n, m;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n = maxChoosableInteger, m = desiredTotal;
        if (n * (n + 1) / 2 < m) return false;
        f = vector<int>(1 << n, -1);
        
        int init = 0;
        dfs(init);
        
        return f[init];
    }
    
private:
    
    bool dfs(int state) {
        if (f[state] != -1) return f[state];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (state >> i & 1) {
                sum += i + 1;   // 0 => 1 base
            }
        }
        
        for (int i = 0; i < n; i++) {
            if ((state >> i & 1) == 0) {
                if (sum + i + 1 >= m) return f[state] = 1;
                if (!dfs(state + (1 << i))) return f[state] = 1;
            }
        }
        
        return f[state] = 0;
    }
};