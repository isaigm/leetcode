// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
    public boolean repeatedSubstringPattern(String s) {
       if(s.length() == 1) return false;
        ArrayDeque<Character> dq = new ArrayDeque<Character>();
        String substr = "";
        boolean flag = true;
        for(int i = 0; i < s.length(); i++){

            char ch = s.charAt(i);
            if(dq.contains(ch)){
                if(flag) substr += dq.getFirst();
                if(dq.getFirst() != ch) return false;
                dq.removeFirst();
                if(dq.size() == 0) flag = false;
            }else{
                dq.add(ch);
            }
        }
        if(dq.isEmpty()) return true;
        String aux = "";
        while (!dq.isEmpty()){
            aux += dq.getFirst();
            dq.removeFirst();
        }
    
        return aux.equals(substr);
    }
}