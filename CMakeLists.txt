PROJECT( AssetsReceiver )
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)



INCLUDE_DIRECTORIES(
    headers
    
)

#link_directories( ${Boost_LIBRARY_DIR} )

SET( CMAKE_CXX_FLAGS "-g -Wall -std=c++11" )

SET( SOURCE_PATH srcs )

SET( CPP

    ${SOURCE_PATH}/main.cpp
    ${SOURCE_PATH}/skel/app_stand_alone.cpp
    ${SOURCE_PATH}/ar/assets_receiver.cpp
    ${SOURCE_PATH}/tcp/http_client.cpp
    ${SOURCE_PATH}/util/str_ascii_helper.cpp
    ${SOURCE_PATH}/util/csv_ascii_helper.cpp
    ${SOURCE_PATH}/util/file_helper.cpp
)

SET( EXE AssetsReceiver )


ADD_EXECUTABLE(
    ${EXE}
    ${HPP}
    ${CPP}
)

TARGET_LINK_LIBRARIES(
    ${EXE}
    log4cxx
    curl
    ncurses
    panel
    menu
    form
)
