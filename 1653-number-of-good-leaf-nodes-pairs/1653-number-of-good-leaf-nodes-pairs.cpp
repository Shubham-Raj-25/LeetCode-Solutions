/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, string& curr, vector<string>& arr){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            arr.push_back(curr);
            return;
        }

        curr.push_back('L');
        solve(root->left, curr, arr);
        curr.pop_back();

        curr.push_back('R');
        solve(root->right, curr, arr);
        curr.pop_back();
    }
public:
    int countPairs(TreeNode* root, int distance) {
        vector<string> arr;
        string curr = "";
        int count = 0;

        solve(root,curr,arr);

        int n = arr.size();
        for(int i = 0; i < n; i++){
            string a = arr[i];
            for(int j = i + 1; j < n; j++){
                string b = arr[j];
                int p = 0, q = 0;
                while(p < a.length() && q < b.length()){
                    if(a[p] == b[q]){
                        p++;
                        q++;
                    }
                    else{
                        break;
                    }
                }

                int totalLength = (a.length() - p) + (b.length() - q);
                if(totalLength <= distance){
                    count++;
                }
            }
        }

        return count;
    }
};