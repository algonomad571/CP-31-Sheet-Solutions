#include<iostream>
#include <algorithm>
#include <priority_queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;

        unordered_map<int,int> freq;
        //Counting the frequency of all the numbers
        for(int num: nums)
        {
            freq[num]++;
        }


    }
};
