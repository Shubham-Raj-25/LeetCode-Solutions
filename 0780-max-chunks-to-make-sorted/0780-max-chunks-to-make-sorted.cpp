class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // O(n2) approach with vector<int>
        int n = arr.size();
        vector<bool> seen(n,false);
        int partitions = 0;

        for(int i=0;i<arr.size();i++){
            seen[arr[i]] = true;
            bool seen_all = true;
            for(int j=0;j<=i;j++){
                if(seen[j] == false){
                    seen_all = false;
                    break;
                }
            }
            if(seen_all){
                partitions++;
            }
        }

        return partitions;
    }
};