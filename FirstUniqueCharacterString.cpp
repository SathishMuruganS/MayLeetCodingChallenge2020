/**
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
**/

class Solution {
public:
    int firstUniqChar(string s) {
		int result = -1;
        vector<int> ch(26, 0);
        
        int n = s.size();
        for(int i =0 ; i< n; i++){
			
			ch[s[i]-'a']++;
		}
		
		for(int i = 0;i<n;i++){
			if (ch[s[i]- 'a'] == 1){
				return i;
			}
		}
        return result;
    }
};
