#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int sumSlidingWindow(vector<int>& nums, int k){
    deque<int> q,q2;
    vector<int> ans, ans2;

    for(int i=0; i<k; i++){
        // for max
        while(!q.empty() && nums[i] >= nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);

        //for min
        while(!q2.empty() && nums[i] <= nums[q2.back()]){
            q2.pop_back();
        }
        q2.push_back(i);
    }

    // for max
    ans.push_back(nums[q.front()]);

    //for min
    ans2.push_back(nums[q2.front()]);

    for(int i=k; i<nums.size(); i++){
        //for max
        if(!q.empty() && i-q.front() >= k){
            q.pop_front();
        }

        while(!q.empty() && nums[i] >= nums[q.back()]){
            q.pop_back();
        }
        q.push_back(i);

        ans.push_back(nums[q.front()]);

        //for min
        if(!q2.empty() && i-q2.front() >= k){
            q2.pop_front();
        }

        while(!q2.empty() && nums[i] <= nums[q2.back()]){
            q2.pop_back();
        }
        q2.push_back(i);

        ans2.push_back(nums[q2.front()]);
    }

    int sum1=0, sum2=0;
    for(int i=0; i<ans2.size(); i++){
        sum1 += ans[i];
        sum2 += ans2[i];
    }
    int s = sum1+sum2;
    return s;
}

int main(){
    
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    
    int sum = sumSlidingWindow(nums,3);
    cout<<sum;
    return 0;
}