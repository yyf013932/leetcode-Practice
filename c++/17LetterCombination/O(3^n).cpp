class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string  a[][4]={{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},
        {"w","x","y","z"},{" "}};
        map<int,vector<string>> letterInfo;
        for(int i=0;i<7;i++){
            if(i!=5)
                letterInfo[i+2]=vector<string>(a[i],a[i]+3);
        }
        letterInfo[7]=vector<string>(a[5],a[5]+4);
        letterInfo[9]=vector<string>(a[7],a[7]+4);
        letterInfo[0]=vector<string>(a[8],a[8]+1);
        vector<string> re;
        for(auto c:digits){
            if(re.size()==0){
                re.insert(re.end(),letterInfo[c-'0'].begin(),letterInfo[c-'0'].end());
            }else{
                vector<string> v;
                for(string s1:re){
                    for(string s2:letterInfo[c-'0']){
                       v.push_back(s1+s2); 
                    }
                }
                re=v;
            }
        }
        return re;
    }
};