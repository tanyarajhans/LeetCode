class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1;
		unordered_set<string> s2;
		unordered_set<string> dict(wordList.begin(),wordList.end());
		if(!dict.count(endWord)) return 0;
		int len=beginWord.size();
		int ans=0;
		s1.insert(beginWord);
		s2.insert(endWord);
		while(!s1.empty() && !s2.empty()){
			ans++;
			if(s1.size()>s2.size()){
				swap(s1,s2);
			}
			unordered_set<string> cur;
			for(string w:s1){
				for(int i=0;i<len;i++){
					char temp=w[i];
					for(char x='a';x<='z';x++){
						w[i]=x;
						if(s2.count(w)){
							return ans+1;
						}
						if(!dict.count(w))continue;
						dict.erase(w);
						cur.insert(w);
					}
					w[i]=temp;

				}
			}

			s1=cur;

		}

		return 0;
    }
};