#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Color : public error_code {

    string name;
    int value;

public:
    void SetValue(int value);
    void SetName(const char *name);

    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
    string GetHexValue() const;
    string GetName() const;
    int GetValue() const;
};