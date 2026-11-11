class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<long long, int> mp;
        for(long long i : nums)
            mp[i]++;
        for(auto it : mp)
            if(it.second >= 2)
                return true;
        return false;
    }
};