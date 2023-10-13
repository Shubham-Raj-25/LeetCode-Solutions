class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = [[] for _ in range(n+1)] 

        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        ans = [0]

        def func(curr, parent):
            
            node_sum = values[curr]

            for child in adj[curr]:
                if child == parent:
                    continue
                node_sum += func(child,curr)
            
            if node_sum % k == 0:
                ans[0] += 1
                return 0
            
            return node_sum

        func(0,-1)

        return ans[0]