#include <iostream>
using namespace std;

int climbStairs(int n) {

    if(n<3){
        return n;
    }

    // current step i=2
    int ways = 2; // ways to reach current step
    // ready for step i+1=3
    int one_back = 2; // ways to reach step before current step (step 3-1=2) -> 1+1,2
    int two_back = 1;   // ways to reach 2 steps before current step (step3-2=1) -> 1
    
    for(int i=2; i<n; i++){ // towards step(i+1)
        // two back : coming from step(i-1) , take a 2-step
        // one back: coming from step(i), take a 1-step
        // ways ,  count for both methods, all methods taken to i-1 + all methods taken to i
        // eg n=3, two_back: 1(+2), one_back: 1+1(+1), 2(+1) -> total ways to reach i+1 = n
        ways = two_back + one_back; 

        // prepare for next (i++), towards step(i+1) eg. i=3, step4
        two_back = one_back; // since i++, now at step(n-2) eg.step2 (2ways)
        one_back = ways;    // now at step(n-1) eg.step3 (3ways)
    }

    return ways;
}