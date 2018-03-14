/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> h;
        for(int i = 0;i<n;i++)
        {
            if(h.find(nums[i])!=h.end())
            {
                if(i-h[nums[i]]<=k)
                {
                    return true;
                }
                else
                {
                    h[nums[i]] = i;
                }
            }
            else
            {
                h[nums[i]]  = i;   
            }
        }
        return false;
        
    }
};


/*
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> myvector(128, 0);
        for(int i=0; i<s.size(); i++)
        {
            myvector[s[i]] ++;
        }
        for(int i = 0;i<t.size();i++)
        {
            myvector[t[i]]--;
        }
        
        
        for(int i =0;i<128;i++)
        {
            if(myvector[i]!=0)
            {
                return false;
            }
        }
        
        return true;
        
    }
};
