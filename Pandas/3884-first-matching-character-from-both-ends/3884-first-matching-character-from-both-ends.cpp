class Solution {
public:
    int firstMatchingIndex(string s) {
        for(int i = 0, j = s.length() - 1; i <= j; i++, j--)
            {
                if(s[i] == s[j])
                    return i;
            }
        return -1;
    }
};