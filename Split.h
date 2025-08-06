
#ifndef Split_h 
#define Split_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void Split(string stn, char pattern, string result[]){
    int posInit=0;
    int posFound=0;
    string splitted;
    int indice=0;

    while(posFound>=0){
        posFound = stn.find(pattern, posInit);
        splitted = stn.substr(posInit, posFound - posInit);
        posInit=posFound+1;
        result[indice]=splitted;
        indice++;

    }
}
#endif  