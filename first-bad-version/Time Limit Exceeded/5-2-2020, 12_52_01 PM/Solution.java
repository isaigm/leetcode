// https://leetcode.com/problems/first-bad-version

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        return search(1, n);
    }
    public boolean isFirst(int k){
        return (k - 1 > 0) && isBadVersion(k) && !isBadVersion(k-1);
    }
    public int search(int left, int right){
        int mid = (left + right) / 2;
        if(left == right) return left;
        else{
            if(isFirst(mid)) return mid;
            if(isBadVersion(left) && isBadVersion(right)) return left;
            if(isBadVersion(mid)){
                if(isBadVersion(left)) return left;
                else return search(left, mid);
            }else return search(mid + 1, right);
        }
    }
}