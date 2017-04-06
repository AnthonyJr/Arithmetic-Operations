//
//  main.cpp
//  Problem3
//
//  Created by Anthony Snow on 10/21/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;


int convert2decimal(vector<int> y, int b);
vector<int> convert2binary(int sum);
vector<int> dec2bin(vector<int> decimal);

int main(int argc, const char * argv[]) {
    vector<int> question1 = {7,7,7,7,3,3,3,3,1,1};
    vector<int> question2 = {5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,9,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
    
    cout << question1.size(); 
    
    for (int i = 0; i < question1.size(); i++) {
        cout << question1[i]; 
    }
    
    vector<int> answer1;
    vector<int> answer2;

    int decimal1;
    int decimal2;
    
    decimal1 = convert2decimal(question1, 2);
    decimal2 = convert2decimal(question2, 2);
    
    answer1 = convert2binary(decimal1);
    answer2 = convert2binary(decimal2);
    
    for (int i = 0; i < answer1.size(); i++) {
        cout << answer1[i];
    }
    for (int j = 0; j <answer2.size(); j++) {
        cout << answer2[j];
    }
    

}

vector<int> convert2binary(int sum){
    int n=ceil(log(sum)/log(2));	//Calculates the # of digits in binary
    vector<int> b(n);		//Vector to hold the digits
    
    for(int i=0;i<n;i++){
        b[i]=(sum%2);
        sum=(sum/2);
    }
    return b;
}

//This function converts the digits in vector y from base b to decimal and
int convert2decimal(vector<int> y, int b){
    int e=1;		//value to hold exponent values
    int sum=0;		//Contains the value of the y digits in decimal
    
    for(int i=0;i<y.size();i++){
        if (i!=0)		//If not in position 0(because b^0=1)
            e=e*b;		//Result of b^i
        sum+=(y[i]*e);		//Add the result of y[i]*e to the sum
    }
    
    return sum;
}

