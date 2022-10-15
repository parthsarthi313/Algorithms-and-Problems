class Solution {
public:
    int lengthOfLastWord(string s) {
       int ind = s.size()-1;
        while(s[ind] == ' ') ind--;
        int cnt = 0;
        while(ind >=0 && s[ind] != ' '){
            cnt++;
            ind--;
        }
        return cnt;
    }
};