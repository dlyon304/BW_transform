// BW_transform.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 
#include <sstream>
#include <unordered_map> 




void bucketSort(unsigned int* I, unsigned int* V, std::string S);
void setGroupLengths(unsigned int* V, int* L, unsigned int len);




int main()
{
    bool debug = true;

    //Path for text file 230,481,013 chars long
    std::string text_path = "C:\\Users\\Daniel\\Desktop\\hu-chr1.txt";
    //const unsigned long len = 230481014;

    //test constructs
    const unsigned long len = 13;
    std::string testS = "ACTGTGAGGGAC$";


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

    //std::string S(buffer, len);
    //S = S + "$";
    delete[] buffer;

    unsigned int* I = (unsigned int*) calloc(len, sizeof(int));
    unsigned int* V = (unsigned int*)calloc(len, sizeof(int));
    int* L = (int*) calloc(len,sizeof(int));

    //loads initial values into I and V
    bucketSort(I, V, testS);
    setGroupLengths(V, L, len);

    if (debug) {
        for (int i = 0; i < len; i++) {
            std::cout << testS[I[i]];
        }
        std::cout << std::endl;
        for (int i = 0; i < len; i++) {
            std::cout << V[i];
        }
        std::cout << std::endl;
        for (int i = 0; i < len; i++) {
            std::cout << L[i];
        }
        std::cout << std::endl;
    }

}


void bucketSort(unsigned int* I, unsigned int* V, std::string S) {
    unsigned int A = 0;
    unsigned int C = 0;
    unsigned int G = 0;
    unsigned int T = 0;

    unsigned int len = S.length();

    for (unsigned int i = 0; i < len-1; i++) {
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
            std::cout << "Unknown char " << std::endl;
        }
    }
    T = A + C + G + 1;
    G = A + C + 1;
    C = A + 1;
    A = 1;

    //std::cout << A << C << G << T << std::endl;

    I[0] = len - 1;

    for (unsigned int i = 0; i < len - 1; i++) {
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


    V[0] = 0;

    for (unsigned int i = 1; i < len; i++) {
        if (i < A) {
            V[i] = A-1;
        }
        else if (i < C) {
            V[i] = C-1;
        }
        else if (i < G) {
            V[i] = G-1;
        }
        else {
            V[i] = T-1;
        }
    }

}

void setGroupLengths( unsigned int* V, int* L, unsigned int len) {
    unsigned int i = 1;
    while (i < len) {
        int g = V[i];
        if (g == i) {
            int temp = i;
            while (g == V[i]) {
                g++;
                i++;
            }
            L[temp] = temp - (g - 1) - 1;
        }
        else {
            L[i] = g - i + 1;
            //std::cout << "Setting group length at " << i << " to " << g - i + 1 << std::endl;
            i = g + 1;
        }
    }
}


