/*Question:- Given an array, the sum of two numbers in the array equal to a given number K exists .
Find the indices of those 2 numbers.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twosum_two(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int rem = target - nums[i];
        auto te = mp.find(rem);
        if(te == mp.end())
            mp[nums[i]] = i;
        else{
            return {te->second, i};
            }
        }
    return {};
}

int main()
{
    vector<int> num={1,2,0,3,5,7};
    int k = 4;
    vector<int> ans = twosum_two(num,k);
    for(auto it:ans)
        cout<<it<<" ";
    return 0;

}

//@Soubhik_Ghosh
//TC -> O(N)
//SC -> O(N)