//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      CSV ASCII Helper header
//
//======================================================================

#ifndef __UTIL_CSV_ASCII_HELPER_HPP__
#define __UTIL_CSV_ASCII_HELPER_HPP__

#include <vector>
#include <string>
#include <functional>

//!-----------------------------------------------------------------------------
//!
//! \brief
//!    Reads an ASCII CSV file.
//!
//! \details
//!    This function receives an array as buffer 
//!    to store the random C string generated.
//!
//! \param [out]
//!    row_handler   A row callback when a row is gotten.
//!
//! \param [in]
//!    token         Character to be utilized as separator character.
//!
//! \param [in]
//!    file          Relative or absolute path of csv file to read.
//!
//! \return
//!    void
//!
extern int
read_csv( const char file[] , const char token , std::function<void(std::vector< std::string >&& v)> row_delegate );

#endif  /* __UTIL_CSV_ASCII_HELPER_HPP__ */
