//
//  main.cpp
//  CS 2450 Palindrome Project
//
//  Created by Dustin Hurst on 2/14/15.
//  Copyright (c) 2015 Dustin Hurst. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class Palindrome{ //class that will find and calculate the palindrome
    public:
    
    void printStr(char *str, int low, int high){  //function to print the longest palindrome
        for(int i = low; i <= high; ++i )
            cout << str[i];
    }
    
    int longestPalindrome(char *str){ //function to find the longest palindrome and tally up its length
        int maxLength = 1;
        int start = 0;
        int len = strlen(str);
        int low, high;
        for(int i = 0; i < len; ++i){
            low = i -1;
            high = i + 1;
            while (low >= 0 && high < len && str[low] == str[high]){ //assuming the palindrome will be odd
                if(high - low + 1 > maxLength){
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
            
        }
        cout << "Longest palindrome is: ";
        printStr(str, start, start + maxLength - 1);
        return maxLength;
    }
};

int main(int argc, const char * argv[]) {
    
    ifstream inFile;
    
    cout << "Please input file name: " << flush; //read an input file
    while(true){
        string inFileName;
        getline(cin, inFileName);
        inFile.open(inFileName.c_str());
        if(inFile)break;
        cout << "Invalide entry. Please enter file name: " << flush;
    }
    
    char str[1000];                 //assuming the file has less than 1000 chars
    for(int i = 0; i < 1000; ++i){
        inFile >> str[i];
        
    }
    
    inFile.close();
    
    Palindrome pal;
    printf("\nLength is: %d",pal.longestPalindrome(str)); //output is just to the console
    cout << endl;
    
    return 0;
}
