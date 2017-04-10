
 bool com(ListNode* node1,ListNode * node2){
        return node1->val < node2->val;
}
    
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(vector<ListNode*>::iterator it=lists.begin();it<lists.end();){
            if(*it==NULL){
                it=lists.erase(it);
            }else{
                it++;
            }
        }
        int length=lists.size();
        if(length==0){
            return NULL;
        }
        if(length==1){
            return lists[0];
        }
        ListNode *re=NULL,*reIt=NULL;
        sort(lists.begin(),lists.end(),com);
        while(lists.size()){
            if(!re){
                re=lists[0];
                reIt=re;
            }else{
                reIt->next=lists[0];
                reIt=reIt->next;
            }
            if(!lists[0]->next){
                lists.erase(lists.begin());
            }else{
                lists[0]=lists[0]->next;
                for(int i=1;i<lists.size();i++){
                    if(lists[i-1]->val > lists[i]->val){
                        ListNode * tem=lists[i];
                        lists[i]=lists[i-1];
                        lists[i-1]=tem;
                    }else{
                        break;
                    }
                }
            }
        }
        reIt->next=NULL;
        return re;
    }
};