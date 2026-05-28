#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string input, result = "";
    int caesar_number = 3, letter_index, actual_index, alphabets_size;
    vector<char> lower_alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> larger_alphabets = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    alphabets_size = lower_alphabets.size();
    if (alphabets_size != larger_alphabets.size()) {
        cout << "Error: This program contains some invalid codes." << endl;
        exit(1);
    }

    cout << "This is a decryptor of Caesar Cipher." << endl;
    cout << "Input a cipher code: ";
    cin >> input;

    for (char letter : input) {
        auto lower_index = find(lower_alphabets.begin(), lower_alphabets.end(), letter);
        auto larger_index = find(larger_alphabets.begin(), larger_alphabets.end(), letter);
        if (lower_index == lower_alphabets.end() && larger_index == larger_alphabets.end()) {
            result += letter;
            continue;
        } else if (lower_index != lower_alphabets.end()) {
            letter_index = *lower_index - *lower_alphabets.begin();
            actual_index = letter_index < caesar_number
                ? alphabets_size + letter_index - caesar_number
                : letter_index - caesar_number;

            result += lower_alphabets.at(actual_index);
        } else {
            letter_index = *larger_index - *larger_alphabets.begin();
            actual_index = letter_index < caesar_number
                ? alphabets_size + letter_index - caesar_number
                : letter_index - caesar_number;

            result += larger_alphabets.at(actual_index);
        }
    }

    cout << "Successfully decrypted! Result is '" << result << "'" << endl;
}
