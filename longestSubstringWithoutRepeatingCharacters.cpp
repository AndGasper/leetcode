class Solution {
public:
    /**
    * @name alreadyExists
    * @description - Check if some character already exists in some string
    * @param {char} someCharacter - some character
    * @param {string} someString - some string
    * @return {bool} alreadyExists
    */
    bool alreadyExists(char someCharacter, string someString) {
        bool alreadyExists = false; 
        unsigned lengthOfSomeString = someString.length();
        for (unsigned i = 0; i < lengthOfSomeString; i++) {
            // hmm, likely a more elegant means of detecting literal space is available...?
            if (someCharacter == someString[i]) {
                alreadyExists = true;
                i = lengthOfSomeString + 1; // bail out 
            }
        }
        return alreadyExists;
    }
    int lengthOfLongestSubstring(string s) {
        vector<string> potentialStrands;
        string strand = "";
        unsigned originalLengthOfInputString = s.length(); // use this to compensate for mismatched logic
        unsigned lengthOfString = s.length();
        unsigned i = 0; 
        for (; i < s.size();) {
            cout << "\n s.size(): " << s.size();
            if (!alreadyExists(s[i], strand)) {
                strand.append(string(1,s[i]));
                i++;
            } else {
                s = s.substr(strand.length(), s.length());
                cout << "\n s in else block" << s;
                potentialStrands.push_back(strand);
                strand = ""; // strand is now empty/should be reset because we have a new one
                i = 0;
            }
        }
        if (i != 0 ) {
            potentialStrands.push_back(strand);
            strand = "";
        }
        
        string longestStrand = "";
        for (int j = 0; j < potentialStrands.size(); j++) {
            cout << "\n potentialStrands[j]: " << potentialStrands[j]; 
            if (potentialStrands[j].length() > longestStrand.length()) {
                longestStrand = potentialStrands[j];
            }
            // left symmetry? dv | df
            // if (potentialStrands[j].length() == longestStrand.length() && j > 0) {
            //     cout << potentialStrands[j-1].substr(potentialStrands[j-1].length()-1);
            // }
        }
            
//             // but you know I say, well I've been cutting this yarn can I even get anymore multicolor threads longer than the one I've got?

            // s                                    | p w w k e w
            // s.length                             | 0 1 2 3 4 5
            // j                                    | 0
            // i                                    | 0
            // s[i]                                 | "p"
            // longestSubstring                     | ""
            // !alreadyExist("p", "")| T
            // longestSubstring.append(s[i])        | "p" 
            
            // s                                    | p w w k e w
            // s.length                             | 0 1 2 3 4 5
            // j                                    | 0
            // i                                    | 1
            // s[i]                                 | "w"
            // longestSubstring                     | "p"
            // !alreadyExist("w", "p")              | T
            // longestSubstring.append(s[i])        | "pw"
            
            // s                                    | p w w k e w
            // s.length                             | 0 1 2 3 4 5
            // j                                    | 0
            // i                                    | 2
            // s[2]                                 | "w"
            // longestSubstring                     | "pw"
            // !alreadyExist("w", "p")              | F
            // lengthOfLongestSubstring             | 2

            // okay, so now you have hit a case where a value repeats what do you do?
            // if you take the rest of the string? Is there any opportunity to have a longer substring?
            // what do you mean by that?
            // s                                                 | p w w k e w
            // s.length()                                        | 0 1 2 3 4 5
            // j = 0                                             | 0
            // i = 2                                             | 2
            // lengthOfLongestSubstring                          | 2
            // s.subtr(2)                                        |     w k e w
            // s.subtr(2).length                                 | 4
            // if (s.subtr(2).length > lengthOfLongestSubstring) | (4 > 2) => T
            // s.subtr(2)                                        | w k e w
            //                                                   | 0 1 2 3
            // now what? 
            
            // since there is the opportunity for a longer substring 
            // but I don't want to throw out the old string just yet because well, who knows just yet?
            // ^ not wholesale true.
            // it could be p w w w w next, you don't know;
            
            
            // if you had a line segment, and you cut it up
            // chunk by distinct multi color chunk 
            // you're forgetting about the notion of offset that each multi-color chunk is giving you
            // mentally as this imaginary pair of scissors progresses along this multi-color thread of yarn
            // you're forgetting that each segment you cut is to be added to this imaginary cutting motion
            // ROYGBIV
            // RO|RYIB|RRR
            // internal cuts RO<|snip|>RYIB<|snip|>R<|snip|>R<|snip|>R
            
            // so don't change s right away do it right after you realize what's up
            
            
    
        cout << "\n longestStrand: " << longestStrand;
        return int(longestStrand.length());
    }
};
