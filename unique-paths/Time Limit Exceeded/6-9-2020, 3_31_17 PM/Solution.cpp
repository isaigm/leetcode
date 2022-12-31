// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        return aux(m, n, 0, 0);
    }
    int aux(int M, int N, int m, int n){
            // base case
        if (n == N || m == M)
            return 0;

        // if we're at first cell (0, 0)
        if (m == M-1 && n == N-1)
            return 1;

        // include cost of the current cell in path and recur to find minimum
        // of the path from adjacent left cell and adjacent top cell.
        return aux(M, N, m+1, n) + aux(M, N, m, n + 1);
    }
};