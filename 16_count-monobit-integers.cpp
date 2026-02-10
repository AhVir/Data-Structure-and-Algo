class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        int powVal = 0;
        for(int i=0; i<=n; ){
            cout << "i: " << i << " ";
            ans++;

            int powCal = pow(2, powVal);
            i = i+powCal;

            cout << "powCal: " << powCal << endl;
            
            powVal++;
        }

        return ans;
    }
};
