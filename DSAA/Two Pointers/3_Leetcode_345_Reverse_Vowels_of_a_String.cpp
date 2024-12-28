#include <iostream>
#include <string>

bool isVowel(char c) {
    c = std::tolower(c); // Convert to lowercase to handle both cases
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::string reverseVowels(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        while (left < right && !isVowel(s[left])) {
            left++;
        }
        while (left < right && !isVowel(s[right])) {
            right--;
        }
        if (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::string result = reverseVowels(input);
    std::cout << "Reversed Vowels: " << result << std::endl;

    return 0;
}
