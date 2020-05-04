/**
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

**/

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        int ran_n =  ransomNote.size();
        int mag_n =  magazine.size();

        if (ran_n == 0 && mag_n == 0){
            return true;
        }

        for(auto ch: magazine){
            if (mp.find(ch) != mp.end()){
                mp[ch]++;
            }else{
                mp[ch] = 1;
            }
        }

        for (auto ch: ransomNote){
            if(mp.find(ch) != mp.end()){
                if (mp[ch] == 0){
                    return false;
                }else{
                    mp[ch]--;
                    if (mp[ch] == 0){
                        mp.erase(mp[ch]);
                    }
                }
            }else{
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.canConstruct("a", "b")<<endl;
    cout<<s.canConstruct("aa", "ab")<<endl;
    cout<<s.canConstruct("aa", "aab")<<endl;
    return 0;
}
