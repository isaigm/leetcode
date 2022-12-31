// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long int firstBadVersion(long int n) {
        return search(1, n + 1);
    }
    bool isFirst(long int k){
        return (k - 1 > 0) && isBadVersion(k) && !isBadVersion(k-1);
    }
    long int search(long int left, long int right){
        long int mid = (left + right) / 2;
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