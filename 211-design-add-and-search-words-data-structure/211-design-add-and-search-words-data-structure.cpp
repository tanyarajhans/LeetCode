class WordDictionary
{
public:
    struct Node
    {
        Node *links[26];
        bool flag = false;
        bool containsKey(char key)
        {
            return links[key - 'a'];
        }
        bool hasEnd()
        {
            return flag;
        }
        Node *getNode(char key)
        {
            return links[key - 'a'];
        }
        void put(char key)
        {
            links[key - 'a'] = new Node();
        }
        void setEnd()
        {
            flag = true;
        }
    };
    Node *root;
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *p = root;
        for (char key : word)
        {
            if (!p->containsKey(key))
            {
                p->put(key);
            }
            p = p->getNode(key);
        }
        p->setEnd();
    }

    bool search(string word)
    {
        return advanceSearchHelper(word, 0, root);
    }
    bool advanceSearchHelper(string &word, int i, Node *dummy)
    {
        if (word.size() == i)
        {
            return dummy->hasEnd();
        }
        if (word[i] != '.')
        {
            if (dummy->containsKey(word[i]))
            {
                if (advanceSearchHelper(word, i + 1, dummy->getNode(word[i])))
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            for (auto node : dummy->links)
            {
                if (node)
                {
                    if (advanceSearchHelper(word, i + 1, node))
                    {
                        return true;
                    };
                }
            }
        }
        return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */