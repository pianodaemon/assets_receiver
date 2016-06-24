//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      String ASCII Helper header
//
//======================================================================

#ifndef __UTIL_STR_ASCII_HELPER_HPP__
#define __UTIL_STR_ASCII_HELPER_HPP__

#include <vector>
#include <string>
//!-----------------------------------------------------------------------------
//!
//! \brief
//!    Generates an ASCII alpha numeric random C string.
//!
//! \details
//!    This function receives an array as buffer 
//!    to store the random C string generated.
//!
//! \param [out]
//!    strout_ptr    Double pointer where Action is allocated
//!                  and builded.
//! \return
//!    void
//!
extern void
rand_alpha_numeric( char* strout_ptr, const int len );


//!-------------------------------------------------------------------
//! \brief
//!      Trim a string from start.
//!
//! \return
//!     a string with trim applied to the left.
//!
extern std::string&
ltrim( std::string &s );


//!-------------------------------------------------------------------
//! \brief
//!      Trim a string from end.
//!
//! \return
//!     a string with trim applied to the right.
//!
extern std::string&
rtrim( std::string &s );


//!-------------------------------------------------------------------
//! \brief
//!    Trim a string from both ends.
//!
//! \return
//!    a string with trim applied to the both ends.
//!
extern std::string&
trim( std::string &s );


//!-------------------------------------------------------------------
//! \brief
//!    Splits a string as per a delimiter code.
//!
//! \return
//!    a vector with all the new splited string.
//!
extern std::vector< std::string >
split( const std::string &s , char delim );


//!-------------------------------------------------------------------
//! \brief
//|    Remove the ascii code from string when 
//|    appearing.
//|
//! \return
//!    void
//!
extern void
remove_code( char c , std::string &s );


//!-------------------------------------------------------------------
//! \brief
//!    When the last element of a c ascii string is '\r' or '\n'
//|    this function will replace so with an replace with '\0'.
//|
//! \return
//!    void
//!
extern void
chomp( char *value );

#endif /* __UTIL_STR_ASCII_HELPER_HPP__ */
