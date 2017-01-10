//
//  main.cpp
//  TwoSum
//
//  Created by BOEING on 11/01/2017.
//  Copyright © 2017 BOEING. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(int argc, const char * argv[]) {
    
    vector<int> input = {2,7,11,15};
    int target = 9;
    vector<int> output = twoSum(input, target);
    for (int i = 0;  i < output.size(); i++) {
        cout<<output[i]<<" ";
    }
    return 0;
}


vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int>  hash;
    vector<int> ret;
    unordered_map<int, int>::iterator iter;
    for (int i = 0;  i < numbers.size(); i++) {
        int numToFind = target - numbers[i];
        iter = hash.find(numToFind);
        if( iter!= hash.end())
        {
            ret.push_back(i+1);
            ret.push_back(hash[numToFind]+1);
            return ret;
        }
        hash[numbers[i]] = i;
        
    }
    return ret;
}
//vector<int> twoSum(vector<int> &numbers, int target)
//{
//    //Key is the number and value is its index in the vector.
//    unordered_map<int, int> hash;
//    vector<int> result;
//    for (int i = 0; i < numbers.size(); i++) {
//        int numberToFind = target - numbers[i];
//        
//        //if numberToFind is found in map, return them
//        if (hash.find(numberToFind) != hash.end()) {
//            //+1 because indices are NOT zero based
//            result.push_back(hash[numberToFind] + 1);
//            result.push_back(i + 1);
//            return result;
//        }
//        
//        //number was not found. Put it in the map.
//        hash[numbers[i]] = i;
//    }
//    return result;
//}