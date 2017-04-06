//
//  main.cpp
//  Problem6
//
//  Created by Anthony Snow on 10/22/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>


using namespace std;
void reSize(vector<int> x, vector<int> y);
vector<int> subtract(vector <int> x, vector<int> y);
int main(int argc, const char * argv[]) {
    vector<int> one,two,three;
    
}


vector<int> subtract(string file1, string file2, int base){
    int xval, yval, c=0;
    vector<int> num;
    cout << "Performing addition of base " << base << "...." << endl;
    cout << "The sum of " << file1 << " and " << file2 << " is: " << endl;
    
    fstream myfile1(file1 + ".txt");
    fstream myfile2(file2 + ".txt");
    
    
    
    vector<int> x;
    vector<int> y;
    
    while (myfile1 >> xval) {
        x.push_back(xval);
    }
    
    while (myfile2 >> yval) {
        y.push_back(yval);
        
    }
    
    if (y.size() > x.size()) { // if y is a bigger number than x.
        for (int i = x.size(); i < y.size(); i++) {
            x.push_back(0); // put y 0's in vector
        }
    } else if (y.size() < x.size()){
        for (int j = y.size(); j < x.size(); j++) {
            y.push_back(0);
        }
    }
    
    //    for (std::vector<int>::iterator it = x.begin() ; it != x.end(); ++it)
    //        std::cout << ' ' << *it; cout << endl;
    //
    //    for (std::vector<int>::iterator it = y.begin() ; it != y.end(); ++it)
    //        std::cout << ' ' << *it; cout << endl;
    //
    
    
    for (int i = y.size(); i != 0; i--) {
        int sum = c + x[i] + y[i];
        
        if ((sum % base) < base) {
            num.push_back(sum%base);
            c = floor(sum/base); ;
        } else if ((sum % base) >= base){
            num.push_back(sum%base);
            c = floor(sum/base);
        }
        
        
        
    }
    
    
    return num;
}

void outputAnswer(vector<int> answer){
    for (int i = answer.size(); i != 0; i--) {
        cout << answer[i];
    }
    cout << endl;
}
