#include <iostream>
#include <string>
#include <cctype>
#include <iomanip> // for controlling output formatting

using namespace std;

// Function to extract a numeric value from the string
double extractNumeric(const string& input) {
    bool isNegative = false;
    bool hasDecimalPoint = false;
    double result = 0.0;
    double decimalPlace = 1.0;
    size_t i = 0;

    // Handle leading '+' or '-' sign
    if (input[i] == '-') {
        isNegative = true;
        i++;
    } else if (input[i] == '+') {
        i++;
    }

    // Parse the digits before the decimal point
    while (i < input.size() && isdigit(input[i])) {
        result = result * 10 + (input[i] - '0');
        i++;
    }

    // Parse the decimal point if it exists
    if (i < input.size() && input[i] == '.') {
        hasDecimalPoint = true;
        i++;
    }

    // Parse the digits after the decimal point
    while (i < input.size() && isdigit(input[i])) {
        result = result + (input[i] - '0') / (decimalPlace *= 10);
        i++;
    }

    // If we have processed all characters, check if the result is valid
    if (i == input.size() && (hasDecimalPoint || result != 0.0)) {
        return isNegative ? -result : result;
    }

    // If we reach here, the input is invalid
    return -999999.99;
}

int main() {
    string input;

    // Continuously prompt the user for input until "END" is entered
    while (true) {
        cout << "Enter a number (or type 'END' to quit): ";
        getline(cin, input);

        // Exit the loop if the user enters "END"
        if (input == "END") {
            break;
        }

        // Call extractNumeric to process the input
        double extractedValue = extractNumeric(input);

        // Output based on the result
        if (extractedValue == -999999.99) {
            cout << "The input is invalid." << endl;
        } else {
            // Display the extracted value formatted to 4 decimal places
            cout << "The input is: " << fixed << setprecision(4) << extractedValue << endl;
        }
    }

    return 0;
}
