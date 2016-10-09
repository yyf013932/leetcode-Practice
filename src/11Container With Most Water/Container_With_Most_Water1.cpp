class Solution {  
public:  
    int maxArea(vector<int> &height) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int res=0;  
        int n = height.size();  
        int l=0,r=n-1;  
        while(l<r)  
        {  
            res=max(res,min(height[l],height[r])*(r-l));  
            if (height[l]<height[r])  
            {  
                int k=l;  
                while(k<r&&height[k]<=height[l])  
                    k++;  
                l=k;  
                }  
            else  
            {  
                int k=r;  
                while(k>l&&height[k]<=height[r])  
                    k--;  
                r=k;  
             }  
        }  
        return res;  
    }  
};