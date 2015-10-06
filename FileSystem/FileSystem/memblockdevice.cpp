#include "memblockdevice.h"
#include <stdexcept>

MemBlockDevice::MemBlockDevice(int nrOfBlocks): BlockDevice(nrOfBlocks) {

}

MemBlockDevice::MemBlockDevice(const MemBlockDevice &other) : BlockDevice(other) {

}

int MemBlockDevice::Init()
{
	FILE* file;
	int error = fopen_s(&file, "disk", "rb");
	if (error == 2)
	{
		ofstream out;//("disk", std::ios::binary | std::ios::out);
		out.open("disk",  std::ios::binary);
		out.seekp(512 * 256);
		out.write("", 1);
		out.close();
	}
	if (error != 0)
		return error;

	return 0;
}

MemBlockDevice::~MemBlockDevice() {
    /* Implicit call to base-class destructor */
}

MemBlockDevice& MemBlockDevice::operator=(const MemBlockDevice &other) {
   /* delete [] this->memBlocks;*/
    this->nrOfBlocks = other.nrOfBlocks;
    this->freePointer = other.freePointer;
  /*  this->memBlocks = new Block[this->nrOfBlocks];

    for (int i = 0; i < this->nrOfBlocks; ++i)
        this->memBlocks[i] = other.memBlocks[i];*/

    return *this;
}

//char* MemBlockDevice::operator[](int index) const {
//  /*  if (index < 0 || index >= this->nrOfBlocks) {
//        throw std::out_of_range("Illegal access\n");
//    }
//    else {
//        return this->memBlocks[index];
//    }*/
//	const char t[] = { "asd" };
//	return t;
//}

int MemBlockDevice::spaceLeft() const {
    /* Not yet implemented */
    return 0;
}

int MemBlockDevice::writeBlock(int blockNr, const std::vector<char> &vec) {
    int output = -1;    // Assume blockNr out-of-range

    if (blockNr < this->nrOfBlocks && blockNr >= 0) {
        /* -2 = vec and block dont have same dimensions */
        /* 1 = success */
    //    output = this->memBlocks[blockNr].writeBlock(vec);
    }
    return output;
}

int MemBlockDevice::writeBlock(int blockNr, const std::string &strBlock) {
    int output = -1;    // Assume blockNr out-of-range

    if (blockNr < this->nrOfBlocks && blockNr >= 0) {
        /* -2 = str-length and block dont have same dimensions */
        /* 1 = success */
     //   output = this->memBlocks[blockNr].writeBlock(strBlock);
    }
    return output;
}

int MemBlockDevice::writeBlock(int blockNr, const char cArr[]) {
    int output = -1;    // Assume blockNr out-of-range
    if (blockNr < this->nrOfBlocks && blockNr >= 0) {
        output = 1;
        // Underlying function writeBlock cannot check array-dimension.
        //this->memBlocks[blockNr].writeBlock(cArr);
		
		ofstream out;//("disk", std::ios::binary | std::ios::out);
		out.open("disk", std::ios::binary | std::ios::in | std::ios::out);
		out.seekp(blockNr*blocksize);
		out.write(cArr, blocksize);
		out.close();
		
    }
    return output;
}

void MemBlockDevice::readBlock(int blockNr, char* cArr) const {
    if (blockNr < 0 || blockNr >= this->nrOfBlocks)
        throw std::out_of_range("Block out of range");
    else {
        //Block a(this->memBlocks[blockNr]);
       // return a;
		FILE* filePtr;

		int error = fopen_s(&filePtr, "disk", "rb");
		fread(cArr, sizeof(blocksize), 1, filePtr);


    }
}

/* Resets all the blocks */
void MemBlockDevice::reset() {
    /*for (int i = 0; i < this->nrOfBlocks; ++i) {
        this->memBlocks[i].reset('0');
    }*/
}

int MemBlockDevice::size() const {
    return this->nrOfBlocks;
}
