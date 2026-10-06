from collections import deque

class Solution:
    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
        def bfs(u, v, adj):
            vis = [False] * len(adj)
            q = deque([u])
            vis[u] = True
            while q:
                node = q.popleft()
                if node == v:
                    return True
                for nei in adj[node]:
                    if not vis[nei]:
                        vis[nei] = True
                        q.append(nei)
            return False
        n = len(edges)
        adj = [[] for _ in range(n+1)]
        for u,v in edges:
            if adj[u] and adj[v] and bfs(u,v,adj):
                return [u,v]
            adj[u].append(v)
            adj[v].append(u)
        return []