class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        vector<int> result;
        vector<int> copy;
        for(int i = 0; i < nums.size(); i++){
            copy.push_back(nums.at(i));
        }
        sort(nums.begin(),nums.end());
        if(target < 0){
            target *= -1;
        }
        int left = 0;
        int right = 1;
        for(int i = 0; i < nums.size(); i++){
            while(right < nums.size() && nums.at(right) - nums.at(left) < target){
                right ++;
            }
            if(nums.at(right) - nums.at(left) == target){
                break;
            }
            left ++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(copy.at(i) == nums.at(right) || copy.at(i) == nums.at(left)){
                result.push_back(i + 1);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
