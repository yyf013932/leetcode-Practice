class Solution {
public:
    int maxArea(vector<int> &height) {  
    int i = 0, j=height.size()-1;  
    int maxA = 0;  
    while(i < j)  
    {  
        maxA = max(maxA,(j-i)*min(height[i], height[j]));  
        height[i] < height[j] ? i++ : j--;  
    }  
    return maxA;  
}
};