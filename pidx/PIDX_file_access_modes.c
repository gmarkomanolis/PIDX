/*****************************************************
 **  PIDX Parallel I/O Library                      **
 **  Copyright (c) 2010-2014 University of Utah     **
 **  Scientific Computing and Imaging Institute     **
 **  72 S Central Campus Drive, Room 3750           **
 **  Salt Lake City, UT 84112                       **
 **                                                 **
 **  PIDX is licensed under the Creative Commons    **
 **  Attribution-NonCommercial-NoDerivatives 4.0    **
 **  International License. See LICENSE.md.         **
 **                                                 **
 **  For information about this project see:        **
 **  http://www.cedmav.com/pidx                     **
 **  or contact: pascucci@sci.utah.edu              **
 **  For support: PIDX-support@visus.net            **
 **                                                 **
 *****************************************************/
#include "PIDX_inc.h"

PIDX_flags PIDX_file_excl = 1;             // Error creating a file that already exists.
PIDX_flags PIDX_file_trunc = 2;           // Create the file if it does not exist.
PIDX_flags PIDX_file_rdwr = 4;           // Read only.
PIDX_flags PIDX_file_rdonly = 8;             // Reading and writing.
PIDX_flags PIDX_file_wronly = 16;           // Write only. 