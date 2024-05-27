#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
   
   vector<int> ans(nums.size(),1);
   int x;

   for(int i{}; i<nums.size(); i++){
      x = nums[i];

      std::for_each(ans.begin(),ans.begin()+i,[x](int& no){ no *= x;});
      std::for_each(ans.begin()+1+i,ans.end(),[x](int& no){ no *= x;});

   }

   return ans;

}

vector<int> productExceptSelf2(vector<int>& nums) {
   
   int n = nums.size();
   vector<int> ans(n,1);

   // forward pass (up to i)
   int left_product = 1;
   for(int i{}; i<n; ++i){
      ans[i] = left_product;
      left_product *= nums[i];
   }   

   // backward pass (end to before i)
   int right_product = 1;
   for(int i=n-1; i>=0; --i){
      ans[i] *= right_product;
      right_product *= nums[i];
   }

   return ans;
}

vector<int> productExceptSelf3(vector<int>& nums) {
   int n = nums.size();
   vector<int> answer(n);
   answer[0] = 1;

   int prod = 1;

   // start from 1 since first elem, (handled by backwardpass)
   for (int i = 0; i < n - 1; i++) {
      prod *= nums[i];
      answer[i+1] = prod;
   }

   prod = 1;

   // start from n-2 since n-1 is last elem
   for (int i = n - 1; i > 0; i--) {
      prod*=nums[i];
      answer[i-1] *= prod;
   }

   return answer;
}

int main(){

   vector<int> nums = {-1,1,0,-3,3};

   vector<int> ans = productExceptSelf(nums);

   for(auto& no : ans){
      cout << no << "\n";
   }

   return 0;
}