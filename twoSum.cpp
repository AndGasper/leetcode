/**
* Note: This is from leetcode; finally got it. I'm sure this could be better, but I'm still proud of it/little victories;
*/

using namespace std;
class Solution {
    public:
        bool isPresent(int x, int y) {
            return x == y;
        }
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> solution;
            int numberOfValues = nums.size();
            int i = 0;
            // loop over all the values
            // if the target - the current value is greater than 0 
            // then it is a potential solution
            while (i < numberOfValues) {
                int difference = target - nums[i];
                if (abs(difference) >= 0) {
                                    // "jump" to the end of the array
                    int j = numberOfValues - 1;
                    // while j is greater than the current index since it is not supposed to be itself
                    while (j > i) {
                        if (nums[j] == difference && !isAlreadyPresent(solution, j)) {
                            solution.push_back(i);
                            solution.push_back(j);
                        }
                        j--; // avoid infinite loop
                    }
                }
                i++;
            }
            
            return solution;
        }
     bool isAlreadyPresent(vector<int> items, int item) {
         vector<bool> isPresent;
         // if the length of the False's equal the length of what is being compared
         // then the element isn't present
            for (int i = 0; i < items.size(); i++) {
                cout << "\nprintItems - items[i]: " << items[i];
                if (items[i] == item) {
                    return true;
                }   
            }
         return false;
     }
};


// class Thingy {
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             cout << "Thingy.twoSum";
//             vector<int> solution;
//             int numberOfValues = nums.size();
//             int i = 0;
//             while (i < numberOfValues) {
//                 int difference = target - nums[i];
//                 // clear the collection each time since there's another loop
//                 solution.clear();
//                 cout << "target: " << target;
//                 if (difference > 0) {
//                     // solution.push_back(nums[i]);
//                     solution.push_back(i);
//                 }
//                 // "jump" to the end of the array
//                 int j = numberOfValues - 1;
//                 while (j > 0) {
//                     cout << "\nWhat is this at j? " << nums[j];
//                     if (nums[j] == difference) {
//                         // solution.push_back(nums[j]);
//                         solution.push_back(j);
//                     }
//                     j--; // avoid infinite loop
//                 }
                
//                 i++;
//             }
//             printItems(solution);
//             return solution;
//         }
        void printItems(vector<int> items) {
            for (int i = 0; i < items.size(); i++) {
                cout << "\nprintItems - items[i]: " << items[i];
            }
        }
// };




// create an instance of Thingy
// Thingy thingy;
// // exampleArray because I couldn't quite get the anonymous syntax;
// int exampleNumbers[] = {3,2,4};
// // the iterator constructor can also be used to construct from arrays:
// std::vector<int> exampleVector(exampleNumbers, exampleNumbers + sizeof(exampleNumbers) / sizeof(int));
// int target = 6;
// // something is kind of wonky about the behavior of classes in the sandbox.
// vector<int> whatIsThis = thingy.twoSum(exampleVector, target);
