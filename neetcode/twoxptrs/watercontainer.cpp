
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 // time limit exceeded
int maxArea(vector<int>& height) {
    
    int i = 0;
    int j = height.size()-1;
    int max_area = 0;
    int b,h,area;


    while(i<j){

        b = j-i;
        h = min(height[i],height[j]);
        area = b*h;    

        max_area = max(area,max_area);
        cout << "area: " << area << endl;
        cout << "left: " << height[i] << endl;
        cout << "right: " << height[j] << endl;
         cout << "base " << b << "\n\n\n";
        if(h==height[i] && height[i+1]-height[i]>=1){
            i++;
        }else if(h==height[j] && height[j-1]-height[j]>=1){
            j--;
        }else if(h==height[i]){
            i++;
        }else{
            j--;
        }
    }

    return max_area;
}

// simpler (less consideration)
int maxArea2(vector<int>& height) {
    std::ios::sync_with_stdio(0); 
    std::cin.tie(0);
    int res = 0;
    int l = 0; 
    int r = height.size()-1;
    int area;

    while(l<r){
        area = (r-l) * min(height[l],height[r]);
        res = max(area,res);

        if(height[l] < height[r]){
            l++;
        }else{
            r--;
        }
    }

    return res;
}

int main(){
    
    vector<int> height = {1,3,2,5,25,24,5};

    cout << maxArea(height) << endl;
    return 0;
}