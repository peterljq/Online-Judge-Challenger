class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        if(s.size() == 1) return 0;
        else{
            unordered_map<char,int> count;
            for(char c:s){
                count[c]++;
            }
            for(int i = 0; i < s.size(); i++){
                if(count[s[i]] == 1) return i;
            }
            return -1;
        }
    }
};
