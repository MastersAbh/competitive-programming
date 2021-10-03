/**

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

 Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i =0;i<lists.size();i++){
            ListNode* ptr = lists[i];
            while(ptr!=NULL){
                pq.push(ptr->val);
                ptr = ptr->next;
            }
        }
        ListNode* l1 = new ListNode();
        ListNode* p = l1;
        while(!pq.empty()){
            int val = pq.top();
            ListNode* temp = new ListNode(val);
            p->next = temp;
            pq.pop();
            p = p->next;
        }
        return l1->next;
        
    }
};