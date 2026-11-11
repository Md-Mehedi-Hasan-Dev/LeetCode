class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> ans;
        stack<int> mnst;
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            while(!mnst.empty() && (mnst.top() <= nums2[i]))
                mnst.pop();
            nextGreater[nums2[i]] = ((!mnst.empty()) ? mnst.top() : -1);
            mnst.push(nums2[i]);
        }
        for(int num : nums1)
        {
            ans.push_back(nextGreater[num]);
        }
        return ans;
    }
};