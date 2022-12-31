// https://leetcode.com/problems/k-closest-points-to-origin

struct point
{
    int x, y;
};
struct comparator
{
  bool operator()(point &p1, point &p2)
  {
      return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
  }
};
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<point, std::vector<point>, comparator> min_heap;
        std::vector<std::vector<int>> ans;
        for(const auto &p: points)
        {
            point p1 {p[0], p[1]};
            min_heap.push(p1);
            if(min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
        for(int i = 0; i < k; i++)
        {
            auto p = min_heap.top();
            std::vector<int> p1(2);
            p1[0] = p.x;
            p1[1] = p.y;
            ans.push_back(p1);
            min_heap.pop();
        }
        return ans;
    }
};