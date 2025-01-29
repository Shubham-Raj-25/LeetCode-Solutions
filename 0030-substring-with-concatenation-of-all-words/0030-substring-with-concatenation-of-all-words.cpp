class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        int len = words[0].size();
        unordered_map<string,int> baseFreq;
        for(string word : words){
            baseFreq[word]++;
        }

        if(s.length() < n * len){
            return ans;
        }

        for(int start = 0; start < len; start++){
            unordered_map<string,int> currFreq;
            int l = start;
            // we need a SW covering n words of s
            int r = l;
            while(r < n * len){
                string toAdd = s.substr(r,len);
                currFreq[toAdd]++;
                r += len;
            }
            if(currFreq == baseFreq){
                ans.push_back(l);
            }
            // move the window
            // cout << "The starting window is " << l << " -- " << r << endl;
            while(r < s.length()){
                string toAdd = s.substr(r,len);
                currFreq[toAdd]++;

                string toRemove = s.substr(l,len);
                currFreq[toRemove]--;

                if(currFreq[toRemove] == 0){
                    currFreq.erase(toRemove);
                }

                r += len;
                l += len;
                // cout << "Moved to : " << l << " -- " << r << endl;
                // cout << "Added : " << toAdd << "  || Removed : " << toRemove << endl;
                if(currFreq == baseFreq){
                    ans.push_back(l);
                }
            }
        }

        return ans;
    }
};


/*

['---', '---', '---', '---', '---', '---', '---'] n 

per : each word comes once

sliding window of nx length

len: nx 

x times sliding window

words = ["foo","bar"]

yzbarfoothefoobarman

*/