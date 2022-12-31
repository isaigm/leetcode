// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
void aux(std::vector<int> &vect, int rowIndex){
    if(rowIndex == 0){
        vect.push_back(1);
        return;
    }
    if(rowIndex == 1){
        vect.push_back(1);
        vect.push_back(1);
        return;
    }
    aux(vect, rowIndex - 1);
    std::vector<int> aux = vect;
    vect.erase(vect.begin(), vect.end());
    vect.push_back(1);
    for(size_t i = 1; i < aux.size(); i++){
        vect.push_back(aux[i] + aux[i - 1]);
    }
    vect.push_back(1);
}
std::vector<int> getRow(int rowIndex) {
    std::vector<int> res;
    aux(res, rowIndex);
    return res;
}
};