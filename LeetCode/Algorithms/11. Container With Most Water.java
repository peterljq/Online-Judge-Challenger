class Solution {
    public int reverse(int x) {
        int length = 0;
        int copyx = x;
        int reverse = 0;
        int sign = (x < 0)? 1 : 0;
        x = (x < 0)? -1*x : x;
        while(copyx != 0){
            copyx /= 10;
            length += 1;
        }

        while(x != 0){
            reverse += (Math.pow(10,length-1))*(x%10);
            x /= 10;
            length -= 1;
        }
        if(reverse >= Math.pow(2,31)-1 || reverse <= Math.pow(2,31)*(-1)){
            return 0;
        }else{
            reverse = (sign == 1)? -1*reverse : reverse;
            return reverse;
        }
    }
}