class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0)
            return false;
        
        int temp = x;
        long rev = 0;
        
        while(temp > 0){
            int rem = temp % 10;
            rev = (rev*10) + rem;
            temp /= 10;
        }

        return x == rev;
    }
};
