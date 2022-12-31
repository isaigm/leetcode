// https://leetcode.com/problems/lexicographical-numbers

/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    array = []
    for (let i = 1; i <= n; i++ )
        {
            array.push(i);
        }
    return array.sort();
};