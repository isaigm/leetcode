// https://leetcode.com/problems/complement-of-base-10-integer

public class Solution {
     public void ToBinary(int N, StringBuilder res)
        {
            if(N > 0)
            {
                ToBinary(N / 2, res);
                res.Append(N % 2 == 0 ? 1 : 0);
            }
        }
        public int BitwiseComplement(int N)
        {
            if (N == 0) return 1;
            StringBuilder binary = new StringBuilder();
            ToBinary(N, binary);
            return Convert.ToInt32(binary.ToString(), 2);
        }
}