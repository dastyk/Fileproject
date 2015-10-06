#include "filesystem.h"

FileSystem::FileSystem() {

}

int FileSystem::Init()
{
	int error;
	Directory main;
	// Create device file if it does not exist.
	error = mMemblockDevice.Init();
	if (error == 2)
	{

		error = main.WriteToMem(&mMemblockDevice);
		if (error != 1)
			return error;
	}
	else if (error != 0)
		return error;
	else
	{
		main.LoadFromMem(&mMemblockDevice, 0);
	}
	



return 0;
}

