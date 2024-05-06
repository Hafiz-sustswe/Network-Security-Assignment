#include <iostream>
#include <string>
#include<bits/stdc++.h>

// Function to decrypt the ciphertext using a specific shift
std::string decryptCaesar(const std::string& ciphertext, int shift) {
    std::string decrypted = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
            decrypted += static_cast<char>((c - base - shift + 26) % 26 + base);
        } else {
            decrypted += c;
        }
    }
    return decrypted;
}

int main() {
    std::string ciphertext = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    for (int shift = 1; shift <= 25; ++shift) {
        std::string plaintext = decryptCaesar(ciphertext, shift);
        std::cout << "Shift " << shift << ": " << plaintext << std::endl;
    }
    return 0;
}
