class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        queue<int>q;
        vector<int>indegree(numCourses,0);
        //store 
         for(int i =0; i< prerequisites.size(); i++ ){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //indegree u -> v
        for(int i =0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            
        }
        //push into q,indegree having 0
        for(int i =0; i< indegree.size(); i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int>result;
        //Simple BFS and keep storing indegree values equal to 0 into result vector
        while(!q.empty()){
           int v = q.front();
            q.pop();
            for(auto it : adj[v]){
                indegree[it]--;
                 if(indegree[it] == 0)q.push(it);
            }
            result.emplace_back(v);
        }
        //check case 
        return (result.size() == numCourses);
    }
};