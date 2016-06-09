#ifndef __UTIL_DEBUG_TRACER_HPP__
#define __UTIL_DEBUG_TRACER_HPP__

#include "log4cxx/logger.h"
#include "log4cxx/helpers/exception.h"
#include "log4cxx/xml/domconfigurator.h"

#define DEBUG_TRACER_INFO( message )  LOG4CXX_INFO( log4cxx::Logger::getRootLogger() , message )
#define DEBUG_TRACER_TRACE( message ) LOG4CXX_TRACE( log4cxx::Logger::getRootLogger() , message )
#define DEBUG_TRACER_DEBUG( message ) LOG4CXX_DEBUG( log4cxx::Logger::getRootLogger() , message )
#define DEBUG_TRACER_WARN( message )  LOG4CXX_WARN( log4cxx::Logger::getRootLogger() , message )
#define DEBUG_TRACER_ERROR( message ) LOG4CXX_ERROR( log4cxx::Logger::getRootLogger() , message )
#define DEBUG_TRACER_FATAL( message ) LOG4CXX_FATAL( log4cxx::Logger::getRootLogger() , message )

#endif  /* __UTIL_DEBUG_TRACER_HPP__ */
