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

#ifndef __PIDX_HZ_ENCODE_H
#define __PIDX_HZ_ENCODE_H


struct PIDX_hz_encode_struct;
typedef struct PIDX_hz_encode_struct* PIDX_hz_encode_id;

PIDX_hz_encode_id PIDX_hz_encode_init(idx_dataset idx_meta_data, idx_dataset_derived_metadata idx_derived_ptr, int start_var_index, int end_var_index);

int PIDX_hz_encode_create_cache_buffers(PIDX_hz_encode_id id, PIDX_variable* variable_ptr);
int PIDX_hz_encode_delete_cache_buffers();


int PIDX_hz_encode_var(PIDX_hz_encode_id id, PIDX_variable* variable_ptr);

int PIDX_hz_encode_write_var(PIDX_hz_encode_id id, PIDX_variable* variable_ptr);

int PIDX_hz_encode_read_var(PIDX_hz_encode_id id, PIDX_variable* variable);

int PIDX_hz_encode_buf_destroy_var(PIDX_hz_encode_id id, PIDX_variable* variable_ptr);

int PIDX_hz_encode_finalize(PIDX_hz_encode_id id);

#if PIDX_HAVE_MPI
int HELPER_Hz_encode(PIDX_hz_encode_id id, PIDX_variable* variable);
int PIDX_hz_encode_set_communicator(PIDX_hz_encode_id id, MPI_Comm comm);
#endif

#endif