#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to remove leading zeros
string removeLeadingZeros(string num) {
    size_t nonZeroIndex = num.find_first_not_of('0');
    if (nonZeroIndex == string::npos) {
        return "0";
    }
    return num.substr(nonZeroIndex);
}

// Addition of two numbers represented as strings
string addStrings(string num1, string num2) {
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);
    
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    string result;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

// Compare two numbers represented as strings (returns 1 if num1 > num2, -1 if num1 < num2, 0 if equal)
int compareStrings(string num1, string num2) {
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);
    
    if (num1.length() > num2.length()) return 1;
    if (num1.length() < num2.length()) return -1;
    
    for (int i = 0; i < num1.length(); i++) {
        if (num1[i] > num2[i]) return 1;
        if (num1[i] < num2[i]) return -1;
    }
    
    return 0;
}

// Subtraction of two numbers represented as strings (num1 - num2, assumes num1 >= num2)
string subtractStrings(string num1, string num2) {
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);
    
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int borrow = 0;
    string result;
    
    while (i >= 0) {
        int digit1 = num1[i--] - '0' - borrow;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        borrow = 0;
        
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        }
        
        result.push_back((digit1 - digit2) + '0');
    }
    
    reverse(result.begin(), result.end());
    return removeLeadingZeros(result);
}

// Multiplication of two numbers represented as strings
string multiplyStrings(string num1, string num2) {
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);
    
    if (num1 == "0" || num2 == "0") return "0";
    
    int n1 = num1.length();
    int n2 = num2.length();
    string result(n1 + n2, '0');
    
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
            result[i + j + 1] = product % 10 + '0';
            result[i + j] += product / 10;
        }
    }
    
    return removeLeadingZeros(result);
}

// Division of two numbers represented as strings (integer division)
string divideStrings(string num1, string num2) {
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);
    
    if (num2 == "0") return "Error: Division by zero";
    if (compareStrings(num1, num2) < 0) return "0";
    
    string quotient;
    string current;
    
    for (int i = 0; i < num1.length(); i++) {
        current += num1[i];
        current = removeLeadingZeros(current);
        if (compareStrings(current, num2) < 0) {
            quotient += "0";
            continue;
        }
        
        int count = 0;
        string temp = num2;
        while (compareStrings(current, temp) >= 0) {
            temp = addStrings(temp, num2);
            count++;
        }
        
        quotient += to_string(count);
        temp = multiplyStrings(num2, to_string(count));
        current = subtractStrings(current, temp);
    }
    
    quotient = removeLeadingZeros(quotient);
    return quotient.empty() ? "0" : quotient;
}

int main() {
    string num1, num2;
    char op;
    
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> op;
    
    string result;
    switch(op) {
        case '+':
            result = addStrings(num1, num2);
            break;
        case '-':
            if (compareStrings(num1, num2) < 0) {
                result = "-" + subtractStrings(num2, num1);
            } else {
                result = subtractStrings(num1, num2);
            }
            break;
        case '*':
            result = multiplyStrings(num1, num2);
            break;
        case '/':
            result = divideStrings(num1, num2);
            break;
        default:
            result = "Invalid operation";
    }
    
    cout << "Result: " << result << endl;
    return 0;
}
