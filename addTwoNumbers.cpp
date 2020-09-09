/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // literally just trying to translate the Java solution
        // presumably dummyHead because of the whole ->next: [3,4,2] -> [4, 2], [2], [] style business
        ListNode* dummyHead = new ListNode(0);
        ListNode* copyL1 = l1;
        ListNode* copyL2 = l2;
        ListNode* current = dummyHead;
        int carryOver = 0; // in case you know the value rolls over
        int resultValue; // just for readability because it's like what if you had other based counting systems instead of 10
        while (copyL1 != NULL || copyL2 != NULL) {
            // well, I'll be...c++ has ternary expressions? That seems...iffy
            int value1 = (copyL1 != NULL) ? copyL1->val : 0;
            int value2 = (copyL2 != NULL) ? copyL2->val : 0;
            int sum = carryOver + value1 + value2;
            carryOver = sum /10; // seems like there's some type coercion or some such foolishness
            resultValue = sum % 10;
            // must use the new keyword to get that sweet, sweet pointer
            current->next = new ListNode(resultValue);
            current = current->next;
            if (copyL1 != NULL) {
                copyL1 = copyL1->next;
            }
            if (copyL2 != NULL) {
                copyL2 = copyL2->next;
            }
        }
        if (carryOver > 0) {
            current->next = new ListNode(carryOver);
        }
        return dummyHead->next;
    }
};
