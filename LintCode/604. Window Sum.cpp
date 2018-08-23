class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        int sum = 0;
        vector<int> result;
        if(k == 0){}
        else{
            for(int i = 0; i < k; i++){
                sum += nums.at(i);
            }
            result.push_back(sum);
            for(int i = 0; i < nums.size()  - k; i++){
                sum -= nums.at(i);
                sum += nums.at(i + k);
                result.push_back(sum);
            }
        }
        return result;
    }
};
