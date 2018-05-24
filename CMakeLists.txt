cmake_minimum_required( VERSION 2.6)
project (ChatServer)

# The version number.
set (ChatServer_VERSION_MAJOR 1)
set (ChatServer_VERSION_MINOR 0)

#Set include directories.
set (CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "E://Program Files//boost_1_55_0//boost")
set (CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "E://Program Files//boost_1_55_0//boost//lib")


#find boost package.
find_package(Boost 1.55.0 REQUIRED)
if(Boost_FOUND)
	
	message(STATUS "Boost is found in ${BOOST_ROOT}")
	message(STATUS "Boost includes are in ${Boost_INCLUDE_DIR}" )
	message(STATUS "Boost libraries are in ${Boost_LIBRARY_DIR}" )

	include_directories(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
	
	#include_directories($(Boost_INCLUDE_DIRS))

else()
	#Set include directories.
	set (BOOST_ROOT "E:/Program Files/boost_1_55_0/boost")
	set (Boost_INCLUDE_DIR "E:/Program Files/boost_1_55_0/boost")
	set (Boost_LIBRARY_DIR  "E:/Program Files/boost_1_55_0/boost/lib")
	
	include_directories(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
	message(STATUS "Boost include director is now set to ${Boost_INCLUDE_DIR}" )
endif()

# Add the executable
add_executable(ChatServer main.cpp)	
#Install the product
install (TARGETS ChatServer DESTINATION ChatServer/bin)