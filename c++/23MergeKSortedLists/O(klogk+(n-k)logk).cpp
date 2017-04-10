class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // ʹ�ö�����, 
        // 1. ѡ��ÿ��������ͷ������С�����У�
        // 2. �ٰѶѶ�����ϲ������У�
        // 3. ��ѡ����ָ������ټ���С������,�ص�2
        // 4. �������������Ϊ��ʱ�����غϲ�������ͷָ��
        if(lists.empty()) return nullptr;
        vector<ListNode* > heap;
        // 1. ѡ��ÿ��������ͷ������С�����У�
        for(int i = 0; i != lists.size(); i ++){
           if(lists[i]) heap.push_back(lists[i]);
        }
        makeHeap(heap);
        // 2. �ٰѶѶ�����ϲ������У�
        ListNode head(-1); // �ϲ������ı�ͷ
        ListNode* p = &head;
        while(!heap.empty()){
            auto minNode = heap[0];
            p->next = minNode; // ��������
            p = p->next;
            // 3. ��ѡ����ָ������ټ���С������,�ص�2
            auto next = minNode->next;
            if(next) {
                heap[0] = next;
            }else{
                swap(heap[0], heap[heap.size()-1]);
                heap.pop_back();
            }
            minHeap(heap, 1);
        }
        // 4. �������������Ϊ��ʱ�����غϲ�������ͷָ��
        return head.next;
    }
    // ����С����
    // �Ե�����
    void makeHeap(vector<ListNode*> &heap){
        // �����һ��Ԫ�صĸ��ڵ㿪ʼ����С����
        for(int i = heap.size()/2; i >0 ; i --){
            minHeap(heap, i);
        }
    }
    // С����,�Ե�i��Ԫ��Ϊ������С����
    //λ�ô�1��ʼ��ȡԪ��ʱ�ǵ�-1
    // �Զ�����
    void minHeap(vector<ListNode*> &heap, int i){
        int l = i*2;
        int r = l+1;
        int least(i);
        // �����СԪ�ص�λ��
        if((l< heap.size()+1) && heap[l-1]->val<heap[i-1]->val ){
            // ���û�г����߽粢�����ӱȸ���С����
            least = l;
        }
        if(r<heap.size()+1 && heap[r-1]->val<heap[least-1]->val){
            // ���û�г����߽粢���Һ�����С����
            least = r;
        }
        if(least != i){
            swap(heap[i-1], heap[least-1]);
            minHeap(heap, least);
        }
    }
};