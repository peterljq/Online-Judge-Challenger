/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int a;
    int b;
    int aindex,bindex;
    int i;
    int j;
    int aim = target;
    for(i = 0; i<numsSize;i++){
        a = nums[i];
        aindex = i;
        for(j = i+1; j<numsSize;j++){
            b = nums[j];
            bindex = j;
            if(a + b == target){
                    nums[numsSize-2] = aindex;
                    nums[numsSize-1] = bindex;
                    return nums+numsSize-2;
            }
        }
    }
    return 0;
}
