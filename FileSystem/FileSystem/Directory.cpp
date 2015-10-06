#include "Directory.h"



Directory::Directory()
{
	mParent = 0;
	mBlockNr = 0;
}


Directory::~Directory()
{
}

int Directory::LoadFromMem(MemBlockDevice * device, int blockNr)
{
	char data[512];

	//device->readBlock();

	return 0;
}

int Directory::WriteToMem(MemBlockDevice * device) const
{
	int err = device->writeBlock(mBlockNr, ToString());
	return 1;
}

char* Directory::ToString() const
{
	char out[512];
	int point = 0;
	int count = mChildren.size();
	memcpy(out + point, &count, sizeof(int));
	point += sizeof(int);
	for (int i = 0; i < count; i++)
	{
		memcpy(out + point, &mChildren[i], sizeof(int));
		point += sizeof(int);
	}

	return out;
}
