#ifndef BLOCKDEVICE_H
#define BLOCKDEVICE_H

/*
 * Pure virtual class
 */

//#include "block.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
const int blocksize = 512;
class BlockDevice
{
protected:
  //  Block* memBlocks;
    int nrOfBlocks;
    int freePointer;
	ofstream out;
public:
    BlockDevice(int nrOfBlocks);
    BlockDevice(const BlockDevice &other);

    virtual ~BlockDevice();
    virtual int spaceLeft() const = 0;
    virtual int writeBlock(int blockNr, const std::vector<char> &vec) = 0;
    virtual int writeBlock(int blockNr, const std::string &strBlock) = 0;
    virtual int writeBlock(int blockNr, const char cArr[]) = 0;
    virtual void readBlock(int blockNr, char* cArr) const = 0;
    virtual void reset() = 0;
    virtual int size() const = 0;
};

#endif // BLOCKDEVICE_H
