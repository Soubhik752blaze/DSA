/*Questions :- Write a efficient program to find the length of the max contiguous subarray with sum 0 within a one-dimensional array of numbers that has the largest sum.*/
#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[],int n)
{
    unordered_map<int,int> mp;
    int maxi = INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            maxi = i+1;
        if(mp.find(sum)!=mp.end())
            maxi=max(maxi,i-mp[sum]);
        else
            mp[sum]=i;       

    }
    return maxi;

}

int main()
{
    int a[] = {2, -3, 4, -1, -4, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int maxlength = maxSubArraySum(a, n);
    cout << "Length of max contiguous array with sum 0 is :- " << maxlength;
    return 0;
}


//@Soubhik_Ghosh
//TC -> o(NlogN)
//SC -> o(N)

//BF -> o(N^2)