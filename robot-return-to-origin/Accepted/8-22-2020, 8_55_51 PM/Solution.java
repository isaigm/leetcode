// https://leetcode.com/problems/robot-return-to-origin

class Solution {
   public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.length(); i++)
        {
            char curr_dir = moves.charAt(i);
            switch (curr_dir)
            {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return (x == 0) && (y == 0);
    }

}