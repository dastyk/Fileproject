#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_
#pragma once
#include <vector>
#include "memblockdevice.h"
using namespace std;
class Directory
{
public:
	Directory();
	virtual ~Directory();

	int LoadFromMem(MemBlockDevice * device, int blockNr);
	int WriteToMem(MemBlockDevice* device);
	char* ToString() const;
private:
	std::vector<int> mChildren; // BlockNr of children
	int mParent; // BlockNr of Parent
	int mBlockNr;

};

#endif