// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return search(1, n + 1);
    }
    bool isFirst(int k){
        return (k - 1 > 0) && isBadVersion(k) && !isBadVersion(k-1);
    }
    int search(int left, int right){
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
};