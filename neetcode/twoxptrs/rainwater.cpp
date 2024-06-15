#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int old_trap(vector<int>& height) {
    std::ios::sync_with_stdio(0); 
    std::cin.tie(0);
    
    if(height.size()<3){return 0;}
    if(height.size()==3 && height[1]>height[0] && height[1]>height[2]){return 0;}

    int res = 0;
    int shade = 0, area = 0, h = 0;
    int l = 0, r = 1;
    bool done = false;

    while(r<height.size() && !done){
         cout << "\nl r : " << l << " " << r << "\n";
        if(height[l]==0 || ((height[r]>=height[l]) && r-l==0)){
            l++;
            r++;
        }else if(height[r]<height[l] && r<height.size()-1){
            r++;
        }else{
            if(r==height.size()-1 && height[r]<=height[r-1]){r--;done=true;}

            h = min(height[l],height[r]);
            for_each(height.begin()+l+1,height.begin()+r,[h,&shade](int &n){
                if(n>h){
                    shade += h;
                    // cout << "added shade " << shade << "\n";
                }else{
                    shade += n;
                    // cout << "added shade " << shade << "\n";
                }
            });
            area = h*(r-l-1) - shade;
            res += area;

            // cout << "\n\nl: " << l << endl;
            // cout << "r: " << r << endl;
            // cout << "shade: " << shade << endl;
            // cout << "area: " << area << endl;
            
            l = r;
            r++;
            area = 0;
            shade = 0;
        }
    }

    return res;
}

int trap(vector<int>& height) {

    if(height.size()<3){return 0;}

    int l = 0, r = height.size()-1;
    int maxL = height[l], maxR = height[r];
    int res = 0;

    while(l<r){
        if(maxL<maxR){
            l++;
            maxL = max(maxL,height[l]);
            res += maxL - height[l];
        }else{
            r--;
            maxR = max(maxR,height[r]);
            res += maxR - height[r];
        }
    }
    return res;
}


int main(){

    vector<int> height = {0,2,0};


    // vector<int> height = {4,2,0,3,2,5};
    // vector<int> height = {0,1,2,0,3,0,1,2,0,0,4,2,1,2,5,0,1,2,0,2};
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "rainwater trapped: " << trap(height) << endl;
    return 0;
}