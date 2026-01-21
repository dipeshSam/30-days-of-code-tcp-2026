#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        // Build next greater map using nums2
        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // Elements left in stack have no next greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    // Print result
    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
