# File-Compression-and-Decompression

## Introduction
This C++ program provides functionality for compressing and decompressing text files using a simple Run-Length Encoding (RLE) algorithm. It allows users to compress the content of a text file and create a corresponding program to decompress the compressed file to retrieve the original content.

## Features
- Compression of text files using Run-Length Encoding algorithm.
- Decompression of compressed files to retrieve the original content.
- User-friendly menu interface for selecting compression, decompression, or exit options.

## Usage
1. **Compilation**: Compile the source code (`main.cpp`) using any C++ compiler, such as g++.
    ```bash
    g++ main.cpp -o compression_program
    ```

2. **Execution**: Run the compiled program.
    ```bash
    ./compression_program
    ```

3. **Menu**: Choose from the following options:
    - **1**: Compress a file
    - **2**: Decompress a file
    - **3**: Exit

4. **Input Files**:
    - Place the text file you want to compress in the same directory as the compiled program.
    - Ensure the file name is "input.txt".

5. **Output Files**:
    - Compressed data will be saved in a file named "compressed.txt".
    - Decompressed data will be saved in a file named "decompressed.txt".

## Example
1. Compress a text file:
    - Choose option **1** from the menu.
    - The compressed data will be written to "compressed.txt".

2. Decompress a compressed file:
    - Choose option **2** from the menu.
    - The decompressed data will be written to "decompressed.txt".

## Dependencies
- C++11 or higher compiler.

## Authors
- Saidulla Akmatov

