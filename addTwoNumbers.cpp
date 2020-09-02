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
        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carryOver;
            resultValue = sum % 10;
            carryOver = sum / 10;
            cout << "\n sum: " << sum;
            cout << "\n carryOver: " << carryOver;
            cout << "\n resultValue: " << resultValue;
            solutionValues.push_back(resultValue);
            
            // l1 = l1->next; // now pointing to the next value; so it's like, [2,4,3] -> [4, 3] -> [3] -> []
            // so there's the possibility that they're different sizes
            l1 = l1->next;
            l2 = l2->next;
        }
        // expanding brain meme level logic here.
        ListNode* solutionList = new ListNode(solutionValues[0], nullptr);
        cout << "\n whats the carryOver? " << carryOver;
        // [5], [5]
        // there's carry over
        if (carryOver != 0) {
            solutionList->next = new ListNode(carryOver, nullptr);
        }
        // l1 is shorter than l2 so add the last value of l2; ...assuming the diff is only 1 value *sigh*
        if (l1 == NULL && l2 != NULL) {
            sum = l2->val + carryOver;
            resultValue = sum % 10;
            carryOver = sum / 10;
            solutionList->next = new ListNode(resultValue, nullptr);
            if (carryOver != 0) {
                solutionList->next->next = new ListNode(carryOver, nullptr);
            }
        }
        // if l2 is shorter than l1
        if (l2 == NULL && l1 != NULL) {
            sum = l1->val + carryOver;
            resultValue = sum % 10;
            solutionList->next = new ListNode(resultValue, nullptr);
            carryOver = sum / 10;
            if (carryOver != 0) {
                solutionList->next->next = new ListNode(carryOver, nullptr);
            }
        }
        if (size(solutionValues) >= 2) {
            solutionList->next = new ListNode(solutionValues[1], nullptr);
        }
        if (size(solutionValues) >= 3) {
            solutionList->next->next = new ListNode(solutionValues[2], nullptr);
        }
        
    
        return solutionList;
    }
};
