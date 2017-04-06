//
//  main.cpp
//  Problem2
//
//  Created by Anthony Snow on 10/21/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//  binary to decimal


#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <math.h>

using namespace std;

vector<int> By2inDec(vector<int> z);
vector<int> bin2dec(vector<int> binary);
int main(int argc, const char * argv[]) {
    int x, y;
    vector<int> one, two;
    vector<int> answer1, answer2;

    // insert code here...
    fstream file1("1111111111111111000000111.txt");
    fstream file2("300.txt");
    if (file1) {
        file1 >> x;
        one.push_back(x);
    }
    
    
    while (file2) {
        file2 >> y;
        two.push_back(y);
    }
    
    
    answer1 = bin2dec(one);
    answer2 = bin2dec(two);
    
    for (int i = 0; answer1.size(); i++) {
        cout << answer1[i];
    }
    
    
    
    for (int i = 0; i < answer2.size(); i++) {
        cout << answer2[i];
    }
    
    
    file1.close();
    file2.close();
    return 0;
}


vector<int> bin2dec(vector<int> binary){
    
    vector<int> decimal;
    
    for (int i = binary.size(); i != 0; i--) {
        decimal = By2inDec(decimal);
        if (binary[i] ==1) {
            if (decimal.size() == 0) {
                decimal.push_back(1);
            } else {
                decimal[0] += 1;
            }
            
        }
    }
    
    return decimal;
    
}

vector<int> By2inDec(vector<int> z){
    int c=0;		//Carry value used to perform addition
    int n=z.size();		//Size of the x vector
    
    vector<int> w(n);	//vector that holds value of 2*z in binary
    
    for(int i=0; i<n;i++){
        if((c+z[i]+z[i])>9){
            w[i]=((c+z[i]+z[i])%10);
            c=1;
        }
        else	{
            w[i]=(c+z[i]+z[i]);
            c=0;
        }
    }
    //If there is a carry value left over, insert it into sum vector
    if (c!=0)
        w.push_back(c);
    
    return w;

}

