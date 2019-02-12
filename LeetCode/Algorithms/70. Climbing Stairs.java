class Solution {
    public int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else return climbStairs(n - 2) + climbStairs(n - 1);
    }
}