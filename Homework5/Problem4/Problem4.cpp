//
//  main.cpp
//  Problem4
//
//  Created by Anthony Snow on 10/22/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;
void TrueorFalse(bool ans);



bool compare(string file1, string file2);
int main(int argc, const char * argv[]) {
    bool one,two,three,four,five,six,seven;
    one = compare("", "");
    TrueorFalse(one);
    
    two = compare("", "110");
    TrueorFalse(two);
    
    three = compare("11","");
    TrueorFalse(three);
    
    four = compare("1101011011","1101111011");
    TrueorFalse(four);
    
    five = compare("0001111011", "1100111101");
    TrueorFalse(five);
    
    six = compare("1101", "111101");
    TrueorFalse(six);
    
    
    return 0;
}

bool compare(string file1, string file2){
    int xval,yval,sumx = 0,sumy = 0,indexX = 0,indexY = 0;
    vector<int> x,y;
    
    
    fstream myfile1(file1 + ".txt");
    fstream myfile2(file2 + ".txt");
    
    while (myfile1 >> xval) {
        x.push_back(xval);
    }
    
    while (myfile2 >> yval) {
        y.push_back(yval);
    }
    
    for (int i = x.size(); i != 0; i--) {
        sumx += x[i] + pow(2, indexX);
        indexX++;
    }
    cout << "the sum of x is " << sumx << endl;
    
    for (int j = y.size(); j != 0; j--) {
        sumy += y[j] + pow(2, indexY);
        indexY++;
    }
    cout << "the sum of y is " << sumy << endl;
    
    
    if (sumx >= sumy) {
        return true;
    } else {
        return false; 
    }
    
    
}

void TrueorFalse(bool ans){
    if (ans == true) {
        cout << "true" << endl;
    } else if (ans == false){
        cout << "false" << endl;
    }
}
