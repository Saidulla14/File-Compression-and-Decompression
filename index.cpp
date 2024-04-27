#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to compress text using Run-Length Encoding (RLE)
string compressRLE(const string& input) {
    string compressed;
    int count = 1;
    char prev = input[0];

    for (size_t i = 1; i < input.length(); ++i) {
        if (input[i] == prev) {
            count++;
        } else {
            compressed += prev + to_string(count);
            count = 1;
            prev = input[i];
        }
    }

    // Add the last character and its count
    compressed += prev + to_string(count);

    return compressed;
}

// Function to decompress text using Run-Length Decoding (RLD)
string decompressRLE(const string& input) {
    string decompressed;
    char currentChar;
    int count;

    for (size_t i = 0; i < input.length(); i += 2) {
        currentChar = input[i];
        count = input[i + 1] - '0'; // Convert char to int

        // Append the character count times
        for (int j = 0; j < count; ++j) {
            decompressed += currentChar;
        }
    }

    return decompressed;
}

int main() {
    int choice;
    cout << "Menu:" << endl;
    cout << "1. Compress a file" << endl;
    cout << "2. Decompress a file" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // Open input file
            ifstream inputFile("input.txt");
            if (!inputFile) {
                cerr << "Error: Unable to open input file." << endl;
                return 1;
            }

            // Read input file content into a string
            string inputContent((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

            // Close input file
            inputFile.close();

            // Compress the input content
            string compressedContent = compressRLE(inputContent);

            // Open output file for writing compressed data
            ofstream compressedFile("compressed.txt");
            if (!compressedFile) {
                cerr << "Error: Unable to create compressed file." << endl;
                return 1;
            }

            // Write compressed content to the output file
            compressedFile << compressedContent;

            // Close compressed file
            compressedFile.close();

            cout << "Compression successful. Compressed content written to 'compressed.txt'." << endl;

            break;
        }
        case 2: {
            // Open compressed file
            ifstream compressedFile("compressed.txt");
            if (!compressedFile) {
                cerr << "Error: Unable to open compressed file." << endl;
                return 1;
            }

            // Read compressed file content into a string
            string compressedContent((istreambuf_iterator<char>(compressedFile)), (istreambuf_iterator<char>()));

            // Close compressed file
            compressedFile.close();

            // Decompress the compressed content
            string decompressedContent = decompressRLE(compressedContent);

            // Open output file for writing decompressed data
            ofstream decompressedFile("decompressed.txt");
            if (!decompressedFile) {
                cerr << "Error: Unable to create decompressed file." << endl;
                return 1;
            }

            // Write decompressed content to the output file
            decompressedFile << decompressedContent;

            // Close decompressed file
            decompressedFile.close();

            cout << "Decompression successful. Decompressed content written to 'decompressed.txt'." << endl;

            break;
        }
        case 3: {
            cout << "Exiting the program." << endl;
            break;
        }
        default: {
            cerr << "Invalid choice. Please enter a valid choice." << endl;
            break;
        }
    }

    return 0;
}
