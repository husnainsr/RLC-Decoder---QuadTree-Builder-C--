#pragma once
#include <iostream>
#include "List.h"
#include <string>
using namespace std;
class Image {
    int** arr;
    int row;
    int col;
    int countR;
    string filename;
    int countC;
public:
    Image();
    int** getImage();
    Image(const Image& obj);
    void setSize(int, int);
    void insert(int);
    void setRow(int);
    void setCol(int);
    int getRow();
    int getCol();
    void save(string);
    void hashRead(string);
    void displayImage();
    int getPixel(int, int);
    void setPixel(int, int, int);
    double mean();
    void countPixel();
    void avgPixels();
    void convertNegative();
    void read(string);
    void avgBlack();
    void countPixels();
    string getFileName();
    void RLC_Encoded();
    void RLC_Decoded();
    void RLC_Black();
    void RLC_Negative();

};

