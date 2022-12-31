// https://leetcode.com/problems/reshape-the-matrix

class Solution {
  public int[][] matrixReshape(int[][] nums, int r, int c) {
        int rows = nums.length;
        int cols = nums[0].length;
        if(rows * cols != r * c) return nums;
        int [][] res = new int[r][c];
        int r1 = 0, c1 = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                res[i][j] = nums[r1][c1];
                c1++;
                if(c1 >= cols){
                    c1 = 0;
                    r1++;
                }
            }
        }
        return res;
    }
}