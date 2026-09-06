class Solution:
    def minCost(self, grid: list[list[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        INF = 10**9
        dist = [
            [
                [[INF]*(k+1) for _ in range(5)]
                for _ in range(n)
            ]
            for _ in range(m)
        ]
        pq = []
        dist[0][0][4][0] = grid[0][0]
        heapq.heappush(pq, (grid[0][0],0,0,4,0))
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        while pq:
            cost, r, c, prev_dir, turns = heapq.heappop(pq)
            if cost != dist[r][c][prev_dir][turns]:
                continue
            if r == m-1 and c == n-1:
                return cost
            for direction in range(4):
                nr = r + dr[direction]
                nc = c + dc[direction]
                if nr < 0 or nr >=m or nc < 0 or nc >= n:
                    continue
                new_turns = turns
                if prev_dir != 4 and prev_dir != direction:
                    new_turns+=1
                if new_turns > k:
                    continue
                new_cost = cost + grid[nr][nc]
                if new_cost < dist[nr][nc][direction][new_turns]:
                    dist[nr][nc][direction][new_turns] = new_cost
                    heapq.heappush(
                        pq,
                        (new_cost, nr, nc, direction, new_turns)
                    )
        return -1