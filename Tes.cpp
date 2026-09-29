#include <iostream>
using namespace std;

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        cout << 0;
        return;
    }
    
    int binaryArray[32];
    int i = 0;
    
    while (decimal > 0) {
        binaryArray[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << binaryArray[j];
    }
}

int binaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;
    
    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary = binary / 10;
        base *= 2;
    }
    
    return decimal;
}

int main() {
    int repeat = 1;
    
    while (repeat == 1) {
        int option;
        cout << "[1] Decimal to binary" << endl;
        cout << "[2] Binary to decimal" << endl;
        cout << "Input your option: ";
        cin >> option;
        
        switch (option) {
            case 1: {
                int decimalInput;
                cout << "Input your decimal: ";
                cin >> decimalInput;
                cout << "Your binary is: ";
                decimalToBinary(decimalInput);
                cout << endl;
                break;
            }
            case 2: {
                int binaryInput;
                cout << "Input your binary: ";
                cin >> binaryInput;
                cout << "Your decimal is: " << binaryToDecimal(binaryInput) << endl;
                break;
            }
            default: {
                cout << "Option not valid!" << endl;
                continue;
            }
        }
        
        cout << "Repeat? [0:No/1:Yes]: ";
        cin >> repeat;
        cout << endl;
        
        if (repeat == 0) {
            break;
        }
    }
    
    cout << "Program ends" << endl;
}