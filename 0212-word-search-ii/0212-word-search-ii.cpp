class Solution {
public:
    struct TreiNode{
        char ch;
        int ends; // no of words ending at this node
        TreiNode* child[26]; // adderesses of child nodes -> next character
        string word; // if a word ends at this node then store it
    };

    TreiNode* getNewNode(char c){
        TreiNode* newNode = new TreiNode;
        newNode->ch = c;
        newNode->ends = 0;
        for(int i=0;i<26;i++) newNode->child[i] = NULL;
        newNode->word = "";
        return newNode;
    }

    TreiNode* root = getNewNode('/');

    void insert(string word){
        TreiNode* curr = root;

        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(curr->child[idx] ==  NULL)
                curr->child[idx] = getNewNode(word[i]);
            curr = curr->child[idx];
        }
        curr->ends += 1;
        curr->word = word;
    }

    void func(int i, int j, vector<vector<char>>& board, vector<string>& ans, TreiNode* curr){
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