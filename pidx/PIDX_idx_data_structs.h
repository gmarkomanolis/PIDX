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

/**
 * \file PIDX_idx_data_structs.h
 *
 * \author Sidharth Kumar
 * \author Cameron Christensen
 *
 * IDX related data structs:
 * -- PIDX_variable
 * -- idx_dataset
 * -- idx_dataset_derived_metadata
 */

#ifndef __PIDX_IDX_DATA_STRUCTS_H
#define __PIDX_IDX_DATA_STRUCTS_H

#include "PIDX_memory_layout_data_structs.h"

///
struct PIDX_variable_struct
{
  // Metadata
  int dump_meta_data_ON;                                                ///< Counter set if meta data dumping activated
  
  // General Info
  char var_name[1024];                                                  ///< Variable name
  int values_per_sample;                                                ///< Vector(3), scalar(1), or n
  int bits_per_value;                                                   ///< Number of bits each need
  char type_name[1024];                                                 ///< Name of the type uint8, bob
  PIDX_data_layout data_layout;                                         ///< Row major or column major

  // Memory layout (before, after HZ encoding phase)
  int patch_count;                                                      ///< The actual number of patches (application layout), most probably more than 1 in uintah
  Ndim_box patch[1024];                                                 ///< Pointer to the patches
  HZ_buffer HZ_patch[1024];                                             ///< HZ encoded buffer of the patches
  
  // Memory layout before aggregation 
  int patch_group_count;                                                ///< Number of groups of patches to be passed to aggregation phase
  Ndim_box_group* patch_group_ptr;                                      ///< Pointer to the patch groups
  Ndim_box_group* post_rst_block;                                       ///< Pointer to the patch group after block restructuring
    
  // Block level layout
  PIDX_block_layout VAR_global_block_layout;                            ///< Block layout, specifically when variables might have different extents in the domain
  int *VAR_blocks_per_file;                                             ///< The number of blocks a variable occupy within each file
  int VAR_existing_file_count;                                          ///< The number of files that exists for each of the variables
  int *VAR_existing_file_index;                                         ///< The index of the existing files for each of the variables
  
  //Compression related
  int lossy_compressed_block_size;                                      ///< The expected size of the compressed buffer
  
  //extents fo meta-data
  int64_t *rank_r_offset;                                                   ///< Offset of variables in each dimension
  int64_t *rank_r_count;                                                    ///< Count of variables in each dimension
};
typedef struct PIDX_variable_struct* PIDX_variable;


/// idx_file
struct idx_file_struct
{
  int current_time_step;                                                ///< Time step tracker
  
  int variable_count;
  int variable_index_tracker;
  PIDX_variable variable[1024];
  
  char filename[1024];
  int bits_per_block;
  int blocks_per_file;
  int64_t global_bounds[PIDX_MAX_DIMENSIONS];
  double transform[16];
  char bitSequence[512];
  char bitPattern[512];
  char filename_template[1024];                                         ///< Depends on the time step
  
  int compression_type;                                                 ///< lossy or lossless. 1 for lossy 0 for lossless
  int64_t compression_block_size[PIDX_MAX_DIMENSIONS];                  ///< size of the block at which compression is applied eg. (4x4x4)                                                      
                                                                        ///< the current compression schemes only work in three dimensions
  int64_t compressed_global_bounds[PIDX_MAX_DIMENSIONS];                ///< Compressed global extents
};
typedef struct idx_file_struct* idx_dataset;


/// idx_dataset_derived_metadata
struct idx_dataset_derived_metadata_struct
{
  int *file_bitmap;
  int dimension;
  int samples_per_block;
  int maxh;
  int max_file_count;
  
  int fs_block_size;
  off_t start_fs_block;
  
  PIDX_block_layout global_block_layout;
  int *existing_blocks_index_per_file;
  int existing_file_count;
  int *existing_file_index;
  
  int aggregation_factor;
  Agg_buffer agg_buffer;
  int dump_agg_info;
  char agg_dump_dir_name[512];
  
  int color;
  
  double win_free_time_start;
  double win_free_time_end;
  double win_time_start;
  double win_time_end;
  double ***agg_level_start;
  double ***agg_level_end;
};
typedef struct idx_dataset_derived_metadata_struct* idx_dataset_derived_metadata;

#endif
