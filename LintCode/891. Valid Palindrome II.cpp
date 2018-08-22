class Solution {
public:
    /**
     * @param s: a string
     * @return: nothing
     */
     //https://www.lintcode.com/problem/valid-palindrome-ii
     //you may delete at most one character. Judge whether it is a palindrome.
     
    bool validPalindrome(string &s) {
        // Write your code here
        int left = 0;
        int right = s.size() - 1;
        string sub1;
        string sub2;
        while(left <= right){
            if(((s[left] >= '0' && s[left] <= '9') ||(s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z')) && ((s[right] >= '0' && s[right] <= '9') ||(s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))){
                if(tolower(s[left]) == tolower(s[right])){
                    left++;
                    right--;
                }
                else{
                    sub1 = s.substr(0,left) + s.substr(left+1);
                    sub2 = s.substr(0,right) + s.substr(right+1);
                    if(isPalindrome(sub1) == 1 || isPalindrome(sub2) == 1){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
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
