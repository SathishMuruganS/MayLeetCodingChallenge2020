/**
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
**/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int, int> umap;
        unordered_map<int, int> ump;
        
        if (N == 1){
            return 1;
        }
        
        if (trust.size() == 1){
            return trust[0][1];
        }
        
        for(auto ii: trust){
            if (umap.find(ii[1]) != umap.end()){
                umap[ii[1]]++;
            } else {
                umap[ii[1]] = 1;
            }
            ump[ii[0]] = ii[1];
        }
        
        for(auto mp: umap){
            if (mp.second == N-1 && ump.find(mp.first) == ump.end()){
                return mp.first;
            }
        }
        
        return -1;
    }
};
