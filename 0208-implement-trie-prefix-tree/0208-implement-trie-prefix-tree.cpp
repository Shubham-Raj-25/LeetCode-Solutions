class TrieNode{
public:
    char c;
    vector<TrieNode*> children;
    bool is_finished;

    TrieNode(char c){
        this->c = c;
        is_finished = false;
        for(int i=0;i<26;i++)
            children.push_back(NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('/');
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new TrieNode(c);
            curr = curr->children[c-'a'];
        }
        curr->is_finished = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children[c-'a'])
                return false;
            curr = curr->children[c-'a'];
        }
        return curr->is_finished;
    }   
    
    bool startsWith(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children[c-'a'])
                return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */