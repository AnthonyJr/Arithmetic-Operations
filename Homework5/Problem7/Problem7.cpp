//
//  main.cpp
//  Homework-2
//
//  Created by Anthony Snow on 9/20/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//

#include <iostream>
#include <math.h>       /* pow */
#include <vector>


using namespace std;
int bin2dec(vector<int> binary);
int doModExp(int base, int exponent, int modN);
int main(int argc, const char * argv[]) {
    // insert code here...
    int x,y,N,ans1x,ans1y,ans1N,ans2x,ans2y,ans2N;
    
    vector<int> N1 = {1,1,1,1,1,0,0,0,1,1,1,1,0,1};
    vector<int> x1 = {1,1,0,1,1,1,1,1,1};
    vector<int> y1 = {0,1,0,1,1,0,0,0,1,1,1,1};
    
    vector<int> N2 = {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1};
    vector<int> x2 = {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1};
    vector<int> y2 = {1,0,1,0,1,1,0,0,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1};
        
    
    

    ans1x = bin2dec(x1);
    ans1y = bin2dec(y1);
    ans1N = bin2dec(N1);
    
    ans2x = bin2dec(x2);
    ans2y = bin2dec(y2);
    ans2N = bin2dec(N2);
    
    int answer = doModExp(ans1x,ans1y,ans1N);
    cout << answer << endl;
    
    int answer2 = doModExp(ans2x,ans2y,ans2N);
    cout << answer2 << endl;
    
}


int doModExp(int base, int exponent, int modN){
    if (exponent == 0) {
        return 1;
    } else {
        int z = doModExp(base, (exponent/2), modN);
        
        if (exponent % 2 == 0) {
            int x = z * z;
            x  = x % modN;
            return x;
        } else {
            int x = (z * z) * base;
            x = x % modN;
            return x;
        }
        
    }
}

int bin2dec(vector<int> vector){
    int sum = 0, index = 0;
    for (int i = vector.size(); i != 0; i--) {
        sum += vector[i] + pow(2,index);
        index++;
    }
    return sum;
}

