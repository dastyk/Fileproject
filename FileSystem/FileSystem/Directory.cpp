#include "Directory.h"



Directory::Directory()
{
	mParent = 0;
	mBlockNr = 0;
	mChildren.push_back(1);
	mChildren.push_back(3);
}


Directory::~Directory()
{
}

int Directory::LoadFromMem(MemBlockDevice * device, int blockNr)
{
	char data[512];
	int point = 0;
	device->readBlock(blockNr, data);

	memcpy(&mParent, data + point, sizeof(int));
	point += sizeof(int);

	int count;
	memcpy(&count, data + point, sizeof(int));
	point += sizeof(int);

	for (int i = 0; i < count; i++)
	{
		int temp;
		memcpy(&temp, data + point, sizeof(int));
		mChildren.push_back(temp);
		point += sizeof(int);
	}
	return 0;
}

int Directory::WriteToMem(MemBlockDevice * device)
{
	int err = device->writeBlock(mBlockNr, ToString());
	return 1;
}

char* Directory::ToString() const
{
	char out[512];
	int point = 0;

	memcpy(out + point, &mParent, sizeof(int));
	point += sizeof(int);

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
