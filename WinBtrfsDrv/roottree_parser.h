/* WinBtrfsDrv/roottree_parser.h
 * root tree parser
 *
 * WinBtrfs
 * Copyright (c) 2011 Justin Gottula
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#ifndef WINBTRFSDRV_ROOTTREE_PARSER_H
#define WINBTRFSDRV_ROOTTREE_PARSER_H

#include "types.h"

namespace WinBtrfsDrv
{
	int parseRootTree(RTOperation operation, void *input0, void *output0);
}

#endif