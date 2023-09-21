class Solution {
public:
    void helper(unordered_map<char,int>& mp, char toAdd, char toRemove){
        mp[toAdd]++;
        mp[toRemove]--;
        if(mp[toRemove]==0)
            mp.erase(toRemove);
    }


    bool isItPossible(string word1, string word2) {
        
        unordered_map<char,int> mp1, mp2;

        for(auto it:word1)
            mp1[it]++;
        for(auto it:word2)
            mp2[it]++;
        
        for(char c1='a'; c1<='z';c1++){
            for(char c2='a';c2<='z';c2++){

                if(mp1.count(c1)==0 || mp2.count(c2)==0) continue;
                    
                    helper(mp1,c2,c1);
                    helper(mp2,c1,c2);
                    
                    if(mp1.size()==mp2.size())
                        return true;
                    
                    helper(mp1,c1,c2);
                    helper(mp2,c2,c1);
                
            }
        }

        return false;


    }
};