class Solution {
public:
    //EXPLANATION
/*
start with 1 size array called result= [1]
while(size<=N){
    make a temp array for this iteration
    PUSH ODD NUMBERS from result array
    for(extract numbers from result array){
        let i = extracted number,say 1 and 2*i-1<N
        push(2*1-1)into temp array, temp = {1}
    }
    PUSH EVEN NUMBERS from result array
    for(extract numbers from result array){
        let i = extracted number,say 1 and 2*i<N
        push(2*1)into temp array, temp = {1,2}
    }
    new result array = temp 
}
NEXT ITERATIONS
[1,2]=>Enter while loop =>first for loop, push 2*i-1=1(i=1),then 2*i-1=2*2-1=3 =>{1,3}
    Enter second while loop => (2*1=2),(2*2=4)={1,3,2,4}
[1,3,2,4] => {2*1-1,2*3-1,2*2-1,2*4-1}={1,5,3,7} and even=>{2*1,2*2,2*2,2*4}=>{2,6,4,8}
            => {1,5,3,7,2,6,4,8}
[1,5,3,7,2,4,6,8]......................and so on



*/
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        while(ans.size()<n){
            vector<int> t;
            for(int x: ans)
                if(x*2-1<=n)
                    t.push_back(x*2-1);
            for(int x: ans)
                if(x*2<=n)
                    t.push_back(x*2);
            ans=t;
        }
        return ans;
    }
};