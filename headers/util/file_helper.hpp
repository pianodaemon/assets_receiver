//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      File Helper header
//
//======================================================================

#ifndef __UTIL_FILE_HELPER_HPP__
#define __UTIL_FILE_HELPER_HPP__

#include "util/error_codes.hpp"
#include <string>
#include <vector>

extern std::vector<std::string>
globbing( const char pattern[] );

extern unsigned long
get_file_size( const char file[] );

extern const bool
check_dir_existence( const char path[] );

extern int
create_dir( const char pathname[] , const mode_t mode );

#endif  /* __UTIL_FILE_HELPER_HPP__ */
