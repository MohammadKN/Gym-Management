#ifndef HASHR_H
#define HASHR_H
#include <iostream>
#include <string>

using namespace std;

#define MAX 100 


int Hash(const string password);
void storePassword(string table[], const string password);
void displayTable(string table[]) ; 

#endif

