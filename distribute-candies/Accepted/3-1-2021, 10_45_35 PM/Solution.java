// https://leetcode.com/problems/distribute-candies

class Solution {
    public int distributeCandies(int[] candyType) {
        HashSet<Integer> hs = new HashSet();
        int n = candyType.length;
        for(int i = 0; i < n; i++)
        {
            hs.add(candyType[i]);
        }
        return Math.min(n / 2, hs.size());
    }
}