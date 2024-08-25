class Solution {
public:
    // can be optimised via Trie
    struct node{
        char c;
        int ends; // no of words ending at this character
        string word; // word formed till this character
        node *child[26];
    };

    struct node *getNode(char c){
        node *newNode = new node;
        newNode->c = c;
        newNode->ends = 0;
        newNode->word = "";
        
        for(int i=0;i<26;i++)
            newNode->child[i] = NULL;
        
        return newNode;
    };

    node *root = getNode('/');

    void insert(string s){
        node *curr = root;
        int idx, i = 0;
        while(s[i])
        {
            idx = s[i] - 'a';
            if(curr->child[idx] == NULL)
                curr->child[idx] = getNode(s[i]);
            curr = curr->child[idx];
            i++;
        }
        curr->ends += 1;
        curr->word = s;
    };

    void func(int i, int j, vector<vector<char>>& board, vector<string>& ans, node* curr){
        int idx = board[i][j] - 'a';
        if(board[i][j] == '@' || curr->child[idx] == NULL)
            return;
        
        curr = curr->child[idx];

        if(curr -> ends>0){
            ans.push_back(curr->word);
            curr -> ends -= 1;
        }

        char ch = board[i][j];
        board[i][j] = '@';

        int di[4] = {1,0,-1,0}, dj[4] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int ni = i + di[k], nj = j + dj[k];
            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size()){
                func(ni,nj,board,ans,curr);
            }
        }
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word : words)
            insert(word);
        
        vector<string> ans;

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                func(i,j,board,ans,root);
        
        return ans;
    }
};