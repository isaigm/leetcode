// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:

        graph = dict()
        
        for edge in edges:
            u = edge[0]
            v = edge[1]

            if u not in graph:
                graph[u] = [v]
            else:
                graph[u].append(v)

            if v not in graph:
                graph[v] = [u]
            else:
                graph[v].append(u)


        visited = [False] * n
    
        def dfs(start, end):
            visited[start] = True
            if start == end:
                return True
            for node in graph[start]:
                if not visited[node]:
                    found = dfs(node, end)
                    if found:
                        return True
            return False
        return dfs(start, end)