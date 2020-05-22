/**
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        string ans;

        if (n == 0){
            return ans;
        }

        vector<pair<int,char>> alph(255, make_pair(0, 0));

        for(char ch: s){
            alph[ch].first++;
            alph[ch].second = ch;
        }

        sort(alph.begin(), alph.end(), greater<>());

        for(int i =0;i<255;i++){
            int n1 = alph[i].first;
            for(int j =0;j<n1; j++){
                ans.push_back(alph[i].second);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.frequencySort("tree")<<endl;
    cout<<s.frequencySort("cccaaa")<<endl;
    cout<<s.frequencySort("Aabb")<<endl;
    cout<<s.frequencySort("2a554442f544asfasssffffasss")<<endl;
    cout<<s.frequencySort("Mymommaalwayssaid,\"Lifewaslikeaboxofchocolates.Youneverknowwhatyou'regonnaget.")<<endl;

    return 0;
}
