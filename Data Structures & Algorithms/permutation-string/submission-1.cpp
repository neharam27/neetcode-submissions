class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        array<int,26> count1 = {};
        array<int,26> count2 = {};

        for (char c:s1) {
            count1[c-'a']++;
        }

        int left = 0;

        for (int right = 0;right< s2.length();right++) {

            count2[s2[right] - 'a']++;

            if (right - left + 1 > s1.length()) {
                count2[s2[left] - 'a']--;
                left++;
            }

            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }
};