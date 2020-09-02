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
    void workingThroughTheLogic() {
        
        vector<int> someValues = {1,2,3};
        int lengthOfSomeValues = size(someValues); // starts the count at 0; 
        
//         for (int i = 0; i < lengthOfSomeValues; i++) {
//             cout << "\n someValues[i]: " << someValues[i];
//             ListNode nextNode = ListNode(someValues[i]);
//             if (i == 0) {
//                 ListNode exampleListNode = nextNode;
//                 exampleListNode.next = &nextNode;
//             } else {
//                 // do not redeclare the solution? I couldn't figure out the initial 0 problem and thought you had to declare a variable before you use it
//                 // so it's like???
//                 exampleListNode.next = &nextNode;
//             }
//         }
        
        return;
    }
    void printValues(vector<int> values) {
        for (int i = 0; i < size(values); i++) {
            cout << "\n values[i]: " << values[i];
        }
        return;
    }
    ListNode* addAValueToAList(int someValue, ListNode* aList) {
        aList->next = new ListNode(someValue, nullptr);
        return aList;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // workingThroughTheLogic();
        int carryOver = 0;
        int sum;
        int resultValue;
        vector<int> solutionValues;
        // sum = l1.val + l2.val + carryOver
        // carryOver = sum % 10
        while(l1 && l2) {
            sum = l1->val + l2->val + carryOver;
            resultValue = sum % 10;
            carryOver = sum / 10;
            cout << "\n sum: " << sum;
            cout << "\n carryOver: " << carryOver;
            cout << "\n resultValue: " << resultValue;
            // solutionList->next->val = new ListNode(resultValue);
            // solutionList->val = resultValue;
            solutionValues.push_back(resultValue);
            
            l1 = l1->next; // now pointing to the next value; so it's like, [2,4,3] -> [4, 3] -> [3] -> []
            l2 = l2->next;
        }
        ListNode* solutionList = new ListNode(solutionValues[0], nullptr);
        solutionList->next = new ListNode(solutionValues[1], nullptr);
        solutionList->next->next = new ListNode(solutionValues[2], nullptr);
        
        return solutionList;
    }
};
