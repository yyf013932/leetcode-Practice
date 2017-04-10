class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        if (right == -1)
            return 0;
        int maxLeft = height[left], maxRight = height[right];
        int volume = 0;
        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                if (height[left] <= maxLeft) {
                    volume += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
            } else {
                right--;
                if (height[right] <= maxRight) {
                    volume += maxRight - height[right];
                } else {
                    maxRight = height[right];
                }
            }
        }
        return volume;
    }
};