class Solution {
public:
    bool func(int node,vector<int>& leftChild, vector<int>& rightChild,vector<bool>& vis){
        if(vis[node])
            return false;
        vis[node] = true;
        bool leftValid = true, rightValid = true;
        
        if(leftChild[node]!=-1)
            leftValid = func(leftChild[node],leftChild,rightChild,vis);
        
        if(rightChild[node]!=-1)
            rightValid = func(rightChild[node],leftChild,rightChild,vis);
        
        return leftValid && rightValid;

    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n, false);
        vector<bool> par(n, false);
        set<pair<int,int>> st;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1)
                {
                    par[leftChild[i]] = true;
                    if(st.find({i,leftChild[i]})!=st.end())
                        return false;
                    // cout << i << " " << leftChild[i] << endl;
                    // cout << leftChild[i] << " " << i  << endl;
                    st.insert({i,leftChild[i]});
                    st.insert({leftChild[i],i});

                }
            if (rightChild[i] != -1)
                {
                    par[rightChild[i]] = true;
                    if(st.find({i,rightChild[i]})!=st.end())
                        return false;
                    st.insert({i,rightChild[i]});
                    st.insert({rightChild[i],i});

                }
            
        }

        int parentCount = 0;
        int root = -1;

        for (int i = 0; i < n; i++) {
            if (!par[i]) {
                parentCount++;
                root = i;
            }
        }

        if(parentCount !=1)
            return false;
        

    bool ans = func(root, leftChild, rightChild, vis);

    for(auto it:vis)
        if(!it) return false;
    
    return ans;
}

};