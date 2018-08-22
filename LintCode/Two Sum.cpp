class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        int left = 0;
        int right = numbers.size() - 1;
        int leftnum,rightnum,record1,record2;
        vector<int> result;
        vector<int> copy;
        for(int q = 0; q < numbers.size(); q++){
            copy.push_back(numbers[q]);
        }
        for(int i = numbers.size() - 1; i > 0 ; i--){
            for(int j = 0; j <i; j++){
                if(numbers[j] >= numbers[j+1]){
                    int temp = numbers[j];
                    numbers[j] = numbers[j+1];
                    numbers[j+1] = temp;
                }
            }
        }
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                leftnum = numbers[left];
                rightnum = numbers[right];
                break;
            }
            else if(numbers[left] + numbers[right] > target){
                right--;
            }
            else{
                left++;
            }
        }
        for(int p = 0; p < copy.size(); p++){
            if(copy[p] == leftnum || copy[p] == rightnum){
                record1 = p;
                break;
            }
        }
        for(int a = record1 + 1; a < copy.size(); a++){
            if(copy[a] == leftnum || copy[a] == rightnum){
                record2 = a;
            }
        }
        if(record1 > record2){
            result.push_back(record2);
            result.push_back(record1);
        }
        else{
            result.push_back(record1);
            result.push_back(record2);
        }
        return result;
    }
};
