#include "EncryptionObj.h"

EncryptionObj::EncryptionObj(string textArg) {
    text = textArg;
}

/*
    @param none
    @return
        the class variable TEXT as a string
*/
string EncryptionObj::getText() {
    return text;
}

/*
    @param 1 
        any character
    @return
        an 8-digit binary string based on ASCII values
*/
string EncryptionObj::base10ToBinary(char myChar) {
    int charCode = int(myChar);

    stack<string> binaryStack;
    while (charCode!=0) {
        binaryStack.push(to_string(charCode%2));
        charCode/=2;
    }

    string returnVal = "";
    int loop = binaryStack.size();

    for (int i = 0; i < 8-loop; i++) {
        returnVal+="0";
    }

    for (int i = 0; i < loop; i++) {
        returnVal+=binaryStack.top();
        binaryStack.pop();
    }
    return returnVal;
}

/*
    @param none
    @return
        a string of non-delimited binary values for each character of TEXT
*/
string EncryptionObj::binaryEncrypt() {
    string returnVal = "";
    for (int i = 0; i < text.length(); i++) {
        returnVal+=base10ToBinary(text[i]);
    }
    return returnVal;
}

/*
    split this


    
    binaryDecrypt() and binaryDecrypt(string str)

    @param none OR unencrypted, non-delimited, 8-digit binary string of 0s and 1s
    @return
        a decrypted string of characters taken from the non-delimited string of binary values
*/
string EncryptionObj::binaryDecrypt() {    
    return binaryDecrypt(text);
}

string EncryptionObj::binaryDecrypt(string str) {    
    string returnVal = "";

    if (str.length()<8) {
        return "Insufficient characters";
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i]!='0'&&str[i]!='1') {
            return "Invalid character(s)"; 
        }
    }

    if (str.length()%8!=0) {
        returnVal += "Incomplete number of characters, but a partial answer will be produced: ";
    }
    else {
        returnVal += "Successful and complete conversion: ";
    }

    string tmp = "";
    for (int i = 0; i < str.length()/8; i++) {
        string binary = str.substr(8*i, 8);
        char character;

        int charCode = 0;
        int val = 128;
        for (int j = 0; j < 8; j++) {
            charCode+=(val*(binary[j]-'0'));
            val/=2;
        }
        if (charCode>126||charCode<32) {
            returnVal = "Non-printable characters included: ";
        }
        character = charCode;
        tmp+=character;
    }
    returnVal+=tmp;
    
    return returnVal;
}

/*
    @param none
    @return
        ?
*/
queue<string> EncryptionObj::binaryDecryptRot() {
    queue<string> returnVal;
    string tmp = text;

    for (int i = 0; i < 8; i++) {
        returnVal.push(binaryDecrypt(tmp));
        tmp = tmp.substr(1)+tmp.substr(0,1);
    }

    return returnVal;
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::caesarEncrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::caesarDecrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::vigenereEncrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::vigenereDecrypt() {
    return "Not completed yet";
}