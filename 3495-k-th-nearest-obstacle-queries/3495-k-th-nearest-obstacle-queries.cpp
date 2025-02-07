class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq; // O(K)
        vector<int> ans; // O(n)
        for(auto query : queries){ // TC : O(N)
            int dist = abs(query[0]) + abs(query[1]);
            pq.push(dist);
            if(pq.size() > k){
                pq.pop(); // TC: O(logK)
            }
            ans.push_back(pq.size() == k ? pq.top() : -1);
        }
        return ans;
    }
};


/*

1 <= queries.length <= 2 * 105
-109 <= queries[i][0], queries[i][1] <= 109
1 <= k <= 105
After each query, 
you need to find the distance of the kth nearest obstacle from the origin.

1st -> nearest
2nd -> 2nd nearest

3rd nearest (pq of size k)

1 5 10 2

1 2 5 10

maxHeap of size k 

1 (-1)
5 (-1)
10 (10)


*/ 