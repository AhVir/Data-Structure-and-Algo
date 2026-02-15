class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int a1 = a.length();
        int b1 = b.length();

        int carry = 0;
        for(int i=0; i < min(a1, b1); i++){
            int t1 = a[i] - '0';
            int t2 = b[i] - '0';

            int sum = t1 + t2 + carry;
            if(sum == 3){
                ans += '1';
                carry = 1;
            }
            else if(sum == 2){
                ans += '0';
                carry = 1;
            }
            else{
                carry = 0;
                char temp = sum + '0';
                ans += temp;
            }
        }

        if(a1 == b1){
            if(carry != 0) ans += (carry + '0');
        }

        if(a1 > b1){
            for(int i=b1; i<a1; i++){
                int t1 = a[i] - '0';

                int sum = t1 + carry;
                if(sum == 3){
                    ans += '1';
                    carry = 1;
                }
                else if(sum == 2){
                    ans += '0';
                    carry = 1;
                }
                else{
                    carry = 0;
                    char temp = sum + '0';
                    ans += temp;
                }
            }
            if(carry != 0) ans += (carry + '0');
        }
        else if(a1 < b1){
            for(int i=a1; i<b1; i++){
                int t1 = b[i] - '0';

                int sum = t1 + carry;
                if(sum == 3){
                    ans += '1';
                    carry = 1;
                }
                else if(sum == 2){
                    ans += '0';
                    carry = 1;
                }
                else{
                    carry = 0;
                    char temp = sum + '0';
                    ans += temp;
                }
            }
            if(carry != 0) ans += (carry + '0');

        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
