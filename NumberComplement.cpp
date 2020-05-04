/**
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
**/

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int flag = false;
        int ans = 0;
        for(int i = 31; i>=0; i--){
            if (num>>i & 0x1){
                flag = true;
            }

            if (flag == true){
                if (!(num>>i & 0x1)){
                    ans |= 0x01<<i;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.findComplement(5)<<endl;
    cout<<s.findComplement(7)<<endl;
    cout<<s.findComplement(10)<<endl;

    return 0;
}
