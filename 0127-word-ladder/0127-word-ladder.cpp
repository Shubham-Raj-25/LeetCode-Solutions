class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        queue<string> q;
        int steps = 1;

        for(string word : wordList) st.insert(word);
        
        q.push(beginWord);
        
        while(q.size()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string curr = q.front();
                q.pop();
                if(curr == endWord)
                    return steps;
                for(int j=0;j<curr.length();j++){
                    int old_char = curr[j];
                    for(char c = 'a' ; c <= 'z'; c++){
                        if(c == old_char)
                            continue;
                        curr[j] = c;
                        if(st.count(curr)){
                            st.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = old_char;
                }
            }
            steps++;
        }

        return 0;
    }
};