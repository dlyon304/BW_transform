// BW_transform.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 
#include <sstream>
#include <unordered_map> 




void bucketSort(int* I, std::string S) {
    unsigned long A = 0;
    unsigned long C = 0;
    unsigned long G = 0;
    unsigned long T = 0;

    unsigned long len = S.length();

    for (unsigned long i = 0; i < len; i++) {
        char c = S[i];
        if (c == 'A') {
            A++;
        }
        else if (c == 'C') {
            C++;
        }
        else if (c == 'G') {
            G++;
        }
        else if (c == 'T') {
            T++;
        }
        else {
            std::cout << "One dolla " << std::endl;
        }
    }
    T = A + C + G + 1;
    G = A + C + 1;
    C = A + 1;
    A = 1;

    //std::cout << A << C << G << T << std::endl;

    I[0] = len - 1;

    for (unsigned long i = 0; i < len-1; i++) {
        char c = S[i];
        if (c == 'A') {
            I[A] = i;
            A++;
        }
        else if (c == 'C') {
            I[C] = i;
            C++;
        }
        else if (c == 'G') {
            I[G] = i;
            G++;
        }
        else if (c == 'T') {
            I[T] = i;
            T++;
        }
        else {
            std::cout << "Bucket Sort Error: Unknown char" << std::endl;
        }
    }
    


}

void ternaryQuickSort()


int main()
{


    //Path for text file 230481013 chars long
    std::string text_path = "C:\\Users\\Daniel\\Desktop\\hu-chr1.txt";
    const unsigned long len = 230481014;


    //Define alphabet order
    std::unordered_map<char, int> alphabet;
    alphabet['A'] = 1;
    alphabet['C'] = 2;
    alphabet['T'] = 3;
    alphabet['G'] = 4;
    alphabet['$'] = 0;


    //Read in text
    size_t buffer_size = 1 << 28;
    char* buffer = new char[buffer_size];
    std::ifstream fin(text_path);
    fin.read(buffer, buffer_size);

    std::string S(buffer, len);
    S = S + "$";
    delete[] buffer;

    int* I = (int*)malloc(len);
    int* V = (int*)malloc(len);
    int* L = (int*)malloc(len);

    bucketSort(I, S);

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
