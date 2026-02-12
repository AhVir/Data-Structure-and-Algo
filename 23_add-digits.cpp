class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int temp = num;
            int ansTemp = 0;
            while(temp > 0){
                int digit = temp%10;
                temp = temp/10;
                ansTemp = ansTemp + digit;
            }

            num = ansTemp;
        }

        return num;
    }
};
