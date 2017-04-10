class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        unsigned length = nums.size();
        int i = 0;
        while (i < length) {
            if (nums[i] != (i + 1) && nums[i] > 0 && nums[i] <= length && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }
        for (int j = 0; j < length; j++) {
            if (nums[j] != j + 1)
                return j + 1;
        }
        return length + 1;
    }
};