class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
   //https://www.lintcode.com/problem/remove-duplicate-numbers-in-array/description
   int deduplication(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size == 0) return 0;
        else{
            sort(nums.begin(), nums.end());
            int fast = 0;
            int slow = 0;
            while(fast != size){
                if(nums[fast] != nums[slow]){
                    slow++;
                    int temp = nums[slow];
                    nums[slow] = nums[fast];
                    nums[fast] = temp;
                }
                fast++;
            }
            return slow + 1;
        }
    }
};
