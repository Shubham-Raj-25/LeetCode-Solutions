class Trie{
private:
    Trie* children[26];
    int count = 0;

public:
    void insert(string word){
        Trie* node = this;
        for(char c : word){
            int curr = c - 'a';
            if(!node->children[curr])
                node->children[curr] = new Trie();
            node->children[curr]->count++;
            node = node->children[curr];
            }
        }

    int getPrefixCount(string word){
        Trie* node = this;
        int count = 0;
        for(char c : word){
            int curr = c - 'a';
            if(!node->children[curr])
                return count;
            count += node->children[curr]->count;
            node = node->children[curr];
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        
        for(string word : words)
            root->insert(word);
        
        vector<int> ans;

        for(string word : words)
            ans.push_back(root->getPrefixCount(word));
        
        return ans;

    }
};