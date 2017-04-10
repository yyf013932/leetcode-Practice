class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> info[n+1];
        info[0]=vector<string>(1,"");
        info[1]=vector<string>(1,"()");
        for(int i=2;i<=n;i++){
            for(int k=1;k<=i;k++){
                vector<string> tem;
                int start=k,end=i-k;
                generate(start,end,info,tem);
                info[i].insert(info[i].end(),tem.begin(),tem.end());
            }
        }
        return info[n];
    }
    
    void generate(int start,int end,vector<string> info[],vector<string>&re){
        for(auto s1:info[start-1]){
            for(auto s2:info[end]){
                re.push_back("("+s1+")"+s2);
            }
        }
    }
};