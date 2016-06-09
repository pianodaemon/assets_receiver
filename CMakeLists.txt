PROJECT( AssetReceiver )
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)


FIND_PACKAGE( Boost 


INCLUDE_DIRECTORIES(
    headers
    
)

#link_directories( ${Boost_LIBRARY_DIR} )

SET( CMAKE_CXX_FLAGS "-g -Wall" )

SET( SOURCE_PATH srcs )

SET( CPP

    ${SOURCE_PATH}/main.cpp
    ${SOURCE_PATH}/term-ui/env_reader.cpp
)

SET( EXE ReceiveAssetes )


ADD_EXECUTABLE(
    ${EXE}
    ${HPP}
    ${CPP}
)

TARGET_LINK_LIBRARIES(
    ${EXE}
#    ${Boost_LIBRARIES}
#    xerces-c
#    sqlite3
#    dbus-c++-1
#    log4cxx
#    pthread
    ncurses
)
