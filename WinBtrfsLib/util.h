/* WinBtrfsLib/util.h
 * utility functions
 *
 * WinBtrfs
 * Copyright (c) 2011 Justin Gottula
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include <Windows.h>
#include "types.h"

namespace WinBtrfsLib
{
	void convertTime(const BtrfsTime *bTime, PFILETIME wTime);
	void convertMetadata(const FilePkg *input, void *output, bool dirList);
	void hexToChar(unsigned char hex, char *chr);
	void uuidToStr(const unsigned char *uuid, char *dest);
	void stModeToStr(unsigned int mode, char *dest);
	void bgFlagsToStr(BlockGroupFlags flags, char *dest);
	void dokanError(int dokanResult);
}
