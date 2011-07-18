/* WinBtrfsLib/WinBtrfsLib.cpp
 * public DLL interfaces
 *
 * WinBtrfs
 * Copyright (c) 2011 Justin Gottula
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include "WinBtrfsLib.h"
#include <cassert>
#include <cstdio>
#include <map>
#include <dokan.h>
#include "btrfs_system.h"
#include "init.h"
#include "instance.h"

namespace WinBtrfsLib
{
	void WINBTRFSLIB_API start(MountData mountData)
	{
		DWORD thID = GetCurrentThreadId();
		
		/* ensure that no instance already exists under this thread ID */
		assert(instances.find(thID) == instances.end());

		/* create a new instance entry for this thread */
		instances.insert(std::pair<DWORD, InstanceData *>(thID, new InstanceData()));

		/* load the MountData struct we received into this thread's instance struct */
		InstanceData *thisInst = getThisInst();
		thisInst->mountData = (MountData *)malloc(sizeof(MountData) +
			(mountData.numDevices * sizeof(wchar_t) * MAX_PATH));
		memcpy(thisInst->mountData, &mountData,
			sizeof(MountData) + (mountData.numDevices * sizeof(wchar_t) * MAX_PATH));

		init();
	}

	void WINBTRFSLIB_API terminate()
	{
		InstanceData *thisInst = getThisInst();
		
		cleanUp();
		DokanRemoveMountPoint(thisInst->mountData->mountPoint); // DokanUnmount only allows drive letters


		instances.erase(GetCurrentThreadId());

		exit(0);
	}
}

using namespace WinBtrfsLib;

BOOL WINAPI DLLMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	return TRUE;
}
