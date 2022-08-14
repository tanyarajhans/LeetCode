class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> word_to_node;
        for (int i = 0; i < wordList.size(); i++){
            word_to_node.insert({wordList[i], i});
        }
        if (word_to_node.count(beginWord) == 0){
            wordList.push_back(beginWord);
            word_to_node.insert({beginWord, (int)word_to_node.size()});
        }
        if (word_to_node.count(endWord) == 0){
            return {};
        }
        // printf("establish edges:\n");
        // establish the edges:
        vector<vector<int>> edges(wordList.size());
        for (int i = 0; i < wordList.size(); i++){
            for (int j = 0; j < wordList.size(); j++){
                if (differ_by_one(wordList[i], wordList[j])){
                    edges[i].push_back(j);
                }
            }
        }
        // printf("BFS to find the shorted path\n");
        // BFS search to find the shorted path
        int start_node = word_to_node[beginWord];
        int back_node = word_to_node[endWord];
        queue<pair<int, int>> units; units.push({start_node, 0});
        vector<int> marked(wordList.size(), INT_MAX);   marked[start_node] = 0;
        while(!units.empty()){
            int round_size = units.size();
            for (int i = 0; i < round_size; i++){
                auto unit = units.front();  units.pop();
                
                int update_move = unit.second + 1;
                for (int j = 0; j < edges[unit.first].size(); j++){
                    int update_node = edges[unit.first][j];
                    if (update_move < marked[update_node]){
                        marked[update_node] = update_move;
                        units.push({update_node, update_move});
                    }
                }
            }
        }
        if (marked[back_node] == INT_MAX){
            return {};
        }
        int steps = marked[back_node];
        
        vector<vector<string>> results;
        queue<vector<int>> candidates; candidates.push({back_node});
        while(steps > 0){
            
            int round_size = candidates.size();
            for (int i = 0; i < round_size; i++){
                auto candidate = candidates.front();   
                candidates.pop();
                int node = candidate.back();
                for (int j = 0; j < edges[node].size(); j++){
                    int to_node = edges[node][j];
                    if (marked[to_node] == steps - 1){
                        candidate.push_back(to_node);
                        candidates.push(candidate);
                        candidate.pop_back();
                    }
                }
            }
            steps--;
        }
        // printf("summary:\n");
        while(!candidates.empty()){
            auto candidate = candidates.front();    
            candidates.pop();
            vector<string> result;
            for (int k = candidate.size() - 1; k >= 0; k--){
                result.push_back(wordList[candidate[k]]);
            }
            results.push_back(result);
        }
        return results;
    }
    bool differ_by_one(string &a, string &b){
        
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < a.size(); i++){
            diff += (a[i] != b[i]);
            if (diff > 1) return false;
        }
        return diff == 1;
    }
};