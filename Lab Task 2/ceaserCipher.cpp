#include <iostream>
#include <string>
#include <cctype>  

// Function to decrypt a message encrypted with the Caesar cipher
std::string decryptCaesar(const std::string& ciphertext, int shift) {
    
    std::string decryptedMessage = "";
    
    for (char ch : ciphertext) {
        
        if (isalpha(ch)) { 
            // Check if the character is a letter
            char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
            // Decrypt the character and add it to the decrypted message
            
            decryptedMessage += char((ch - base - shift + 26) % 26 + base);
        
        } else {
            // If not a letter, just add the character as is
            
            decryptedMessage += ch;
        }
    }
    return decryptedMessage;
}

int main() {
    std::string ciphertext = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    // Try all possible shifts from 1 to 25
    for (int shift = 1; shift <= 25; ++shift) {
        
        std::string plaintext = decryptCaesar(ciphertext, shift);
        std::cout << "Shift " << shift << ": " << plaintext << std::endl;
    }
    return 0;
}
