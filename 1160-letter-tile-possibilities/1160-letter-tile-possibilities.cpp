class Solution {
public:
    void func(string &s, string &tiles, unordered_map<char,int>& freq, unordered_set<string> &st){
        for(int i = 0; i<tiles.length(); i++){
            char c = tiles[i];
            if(freq[c] > 0){
                s.push_back(c);
                freq[c]--;
                st.insert(s);
                func(s,tiles,freq,st);
                s.pop_back();
                freq[c]++;
            }
        }
    }


    int numTilePossibilities(string tiles) {
        unordered_set<string>st;
        unordered_map<char,int> freq;
        for(char c : tiles){
            freq[c]++;
        }
        string empty = "";
        func(empty,tiles,freq,st);
        return st.size();
    }
};


/*

n : tiles
AAB

freq

823543
1000000
7 * 6 * 5

*/ 