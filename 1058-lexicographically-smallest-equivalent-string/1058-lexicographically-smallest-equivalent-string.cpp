class Solution {
private:
void unionBySize(int i, int j, vector<int>& par, vector<int>& size) {
    int u = findUPar(i, par);
    int v = findUPar(j, par);

    if (u == v) return;
    else if (size[u] > size[v]) {
        par[v] = par[u];
        size[u] += size[v];
    } else {
        par[u] = par[v];
        size[v] += size[u];
    }
}

int findUPar(int u, vector<int>& par) {
    if (par[u] == u)
        return u;
    return par[u] = findUPar(par[u], par);
}

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26);
        vector<int> size(26,1);
        string ans = "";

        for(int i=0;i<26;i++) par[i] = i;

        for(int i=0;i<s1.length();i++)
            unionBySize(s1[i] - 'a', s2[i] - 'a', par,size);
        
        for(char c : baseStr){
            for(int i=0;i<26;i++){
                if(findUPar(i,par) == findUPar(c-'a',par)){
                    ans.push_back('a' + i);
                    break;
                }
            }
        }

        return ans;
    }
};