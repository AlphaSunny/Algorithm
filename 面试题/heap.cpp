/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0; i<nums.size();++i)
        {
            if(pq.size()<k)
            {
                pq.push(nums[i]);
            }
            
            else
            {
                int min_elem = pq.top();
                if(min_elem<nums[i])
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};


/*
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/
class mycomparison
{
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>&rhs)
    {
        return lhs.first + lhs.second < rhs.first + rhs.second;
    }
};


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        if(m*n==0) return vector<pair<int, int>>();
        
        vector<pair<int, int>> all_pairs;
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                all_pairs.push_back(make_pair(nums1[i], nums2[j]));
            }
        }
        sort(all_pairs.begin(), all_pairs.end(), mycomparison());
        return vector<pair<int, int>>(all_pairs.begin(), all_pairs.begin() + min(k, (int)(all_pairs.size())));
    }
};