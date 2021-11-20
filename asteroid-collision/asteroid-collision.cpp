class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;
        stack<int> s;
        //cases
        // stack top --- incoming asteroid
        // left          left         nothing happens
        // left          right        nothing happens
        // right         left         collision (+-)
        // right          right       nothing happens
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else{
                if(s.top()>0 && asteroids[i]<0){
                    bool f=false;
                    while(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])>abs(s.top())){
                        s.pop();
                        f=true;
                    }
                    bool g=false;
                    if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])==abs(s.top())){
                        s.pop();
                        g=true;
                    }
                    if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])<abs(s.top())){
                        g=true;
                    }
                    if(f && !g)
                        s.push(asteroids[i]);
                }
                else {
                    s.push(asteroids[i]);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};