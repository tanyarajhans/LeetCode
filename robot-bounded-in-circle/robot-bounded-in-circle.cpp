class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0,dx=0,dy=1;
        for (int i = 0; i<instructions.size(); i++)
        {
            if(instructions[i]=='L'){
                int t=dx;
                dx=-dy;
                dy=t;
            }
            else if(instructions[i]=='R'){
                int t=dx;
                dx=dy;
                dy=-t;
            }
            else{
                x+=dx;
                y+=dy;
            }
        }
        if(x==0 && y==0)
            return true;
        if(dx!=0 || dy!=1)
            return true;
        return false;
    }
};