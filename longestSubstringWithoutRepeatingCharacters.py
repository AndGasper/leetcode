class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        totalStringLength = len(s)
        longestStringSet = set()
        index = 0
        otherIndex = 0
        answer = 0
        while (index < totalStringLength and otherIndex < totalStringLength):
            # if the new letter isn't a subset of the running subset
            if not set(s[otherIndex]).issubset(longestStringSet):
                
                # print('\n otherIndex')
                # print(otherIndex)
                longestStringSet.add(s[otherIndex])
                # print('\n longestStringSet')
                # print(longestStringSet)
                # actually increment the index
                otherIndex = otherIndex + 1
                # the meat and potatoes of the logic has to be here
                # find me the maximum between
                # max 0, (0-0) => 0
                # max 0, (0-1) => 0 
                
                # max 0, (1-0) => 1
                
                
                
                answer = max(answer, otherIndex - index)
                # and then the other bamboozle on the logic would be that
                # once otherIndex - index = 0
                
                # print('\n answer:')
                # print(answer)
            else:
                # remove the repeat from this running string
                longestStringSet.remove(s[index])
                # incrememnt the index
                index = index + 1
        
        
        
        return answer
