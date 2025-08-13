
#ifndef Split_h 
#define Split_h
#include <iostream>
#include <string>
using namespace std;

int Split(string stn, char pattern, string result[]) {
    int posInit = 0;
    int posFound;
    int index = 0;

    while ((posFound = stn.find(pattern, posInit)) != string::npos) {
        result[index++] = stn.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
    }

    result[index++] = stn.substr(posInit);
    return index;
}

#endif
