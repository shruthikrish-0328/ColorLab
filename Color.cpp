#include "Color.h"
#include <bitset>

void Color::SetName(const char *name){

    string strName = name;
    this-> name = strName;
}

void Color::SetValue(int value){

    this-> value = value;
}

unsigned char Color:: GetR() const{

    int checkVar = 255;
    int checkVar1 = this->value >> 16;
    unsigned char a = checkVar1 & checkVar;

    return a;
}

unsigned char Color:: GetG() const{

    int checkVar = 255;
    int checkVar1 = this->value >> 8;
    unsigned char a = checkVar1 & checkVar;

    return a;
}

unsigned char Color:: GetB() const{

    int checkVar = 255;
    int checkVar1 = this->value;
    unsigned char a = checkVar1 & checkVar;

    return a;
}

string Color:: GetHexValue() const{

    int value = this->value;
    int divisor = 1;
    int remainder = 0;
    vector<int> valToHex;
    vector<string> finalVector;
    string hexString = "0x";
    string hexString5 = "0x0";
    string hexString4 = "0x00";
    string hexString3 = "0x000";
    string hexString2 = "0x0000";
    string hexString1 = "0x00000";
    bool hex1 = false;
    bool hex2 = false;
    bool hex3 = false;
    bool hex4 = false;
    bool hex5 = false;

    while(divisor != 0){

        divisor = value / 16;
        remainder = value % 16;
        valToHex.push_back(remainder);
        value = divisor;
    }

    //cout << valToHex.size() << endl;

    for(int i = 0; i < valToHex.size(); i++){

        //cout << valToHex.at(i) << endl;
    }

    for(int i = (valToHex.size() - 1); i >= 0; i--){

        if(valToHex.at(i) == 10){
            finalVector.push_back("A");
        }
        else if(valToHex.at(i) == 11){
            finalVector.push_back("B");
        }
        else if(valToHex.at(i) == 12){
            finalVector.push_back("C");
        }
        else if(valToHex.at(i) == 13){
            finalVector.push_back("D");
        }
        else if(valToHex.at(i) == 14){
            finalVector.push_back("E");
        }
        else if(valToHex.at(i) == 15){
            finalVector.push_back("F");
        }
        else{
            finalVector.push_back(to_string(valToHex.at(i)));
        }

    }

    //cout << finalVector.size() << endl;
    //cout << endl;

    for(int i = 0; i < finalVector.size(); i++) {

        if (finalVector.size() == 1) {
            hexString1 += finalVector.at(i);
            hex1 = true;
        } else if (finalVector.size() == 2) {
            hexString2 += finalVector.at(i);
            hex2 = true;
        } else if (finalVector.size() == 3) {
            hexString3 += finalVector.at(i);
            hex3 = true;
        } else if (finalVector.size() == 4) {
            hexString4 += finalVector.at(i);
            hex4 = true;
        } else if (finalVector.size() == 5) {
            hexString5 += finalVector.at(i);
            hex5 = true;
        } else {
            hexString += finalVector.at(i);
        }
    }

    if(hex1){
        return hexString1;
    } else if(hex2){
        return hexString2;
    } else if(hex3){
        return hexString3;
    } else if(hex4){
        return hexString4;
    } else if(hex5){
        return hexString5;
    } else{
        return hexString;
    }

}

string Color:: GetName() const{

    return name;
}

int Color:: GetValue() const {

    return value;
}

