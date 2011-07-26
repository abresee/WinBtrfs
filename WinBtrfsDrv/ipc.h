/* WinBtrfsDrv/ipc.h
 * interprocess communications
 *
 * WinBtrfs
 * Copyright (c) 2011 Justin Gottula
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#ifndef WINBTRFSDRV_IPC_H
#define WINBTRFSDRV_IPC_H

#include <Windows.h>

namespace WinBtrfsDrv
{
	extern char pipeName[MAX_PATH];
	extern int parentPID;
	
	int sendMessage(const char *msg, size_t len, char *buffer, size_t bufLen);
}

#endif
