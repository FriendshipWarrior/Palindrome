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

class Palindrome{
    public:
    
    void printStr(char *str, int low, int high){
        for(int i = low; i <= high; ++i )
            cout << str[i];
    }
    
    int longestPalindrome(char *str){
        int maxLength = 1;
        int start = 0;
        int len = strlen(str);
        int low, high;
        for(int i = 0; i < len; ++i){
            low = i -1;
            high = i + 1;
            while (low >= 0 && high < len && str[low] == str[high]){
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
    
    return 0;
}
