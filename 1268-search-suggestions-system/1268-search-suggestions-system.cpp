class Node {
public:
    bool end;
    vector<Node*> ch;
	
    Node(): end(false), ch(26, nullptr) {}
};

class Trie {
public:
    Node *head = new Node();

    void addWord(string &s) {
        Node *cur = head;
        for (char c: s) {
            if (!cur->ch[c - 'a']) 
                cur->ch[c - 'a'] = new Node();
            cur = cur->ch[c - 'a'];
        }
        cur->end = true;
    }

    vector<string> wordsBeginWith(string &prefix) {
        vector<string> r;
        Node *cur = head;
        for (char c: prefix) {
            if (!cur->ch[c - 'a']) return {};
            cur = cur->ch[c - 'a'];
        }
        dfs(cur, r, prefix);
        return r;
    }

    static void dfs(Node *cur, vector<string> &r, string &wordNow) {
        if (r.size() == 3) 
            return;
        if (cur->end) 
            r.push_back(wordNow);
        for (int i = 0; i < 26; ++i) {
            if (cur->ch[i]) {
                wordNow.push_back((char) ('a' + i));
                dfs(cur->ch[i], r, wordNow);
                wordNow.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        vector<vector<string>> ans;
        Trie trie = Trie();
        for (auto &name: products) 
            trie.addWord(name);
        string prefix;
        for (char c: searchWord) {
            prefix.push_back(c);
            ans.push_back(trie.wordsBeginWith(prefix));
        }
        return ans;
    }
};
