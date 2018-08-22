class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    //https://www.lintcode.com/problem/valid-palindrome
    
    bool isPalindrome(string &s) {
        // write your code here
        int left = 0;
        int right = s.size() - 1;
        while(left <= right){
            if(((s[left] >= '0' && s[left] <= '9') ||(s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z')) && ((s[right] >= '0' && s[right] <= '9') ||(s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))){
                if(tolower(s[left]) == tolower(s[right])){
                    left++;
                    right--;
                }
                else return false;
            }
            else if(((s[left] >= '0' && s[left] <= '9') ||(s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z'))){
                right--;
            }
            
            else{
                left++;
            }
        }
        return true;
    }
};
