class Solution {
public:
bool hasAllCodes(string s, int k) {
    int n = s.size();
    int need = 1 << k;

    if (n - k + 1 < need)
        return false;

    vector<bool> seen(need, false);
    int count = 0;

    int value = 0;

    // Build first window
    for (int i = 0; i < k; i++) {
        value = (value << 1) | (s[i] - '0');
    }

    seen[value] = true;
    count = 1;

    int mask = (1 << k) - 1;

    // Slide window
    for (int i = k; i < n; i++) {
        value = ((value << 1) & mask) | (s[i] - '0');

        if (!seen[value]) {
            seen[value] = true;
            count++;

            if (count == need)
                return true;
        }
    }

    return count == need;
}
};
