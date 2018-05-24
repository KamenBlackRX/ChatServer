cmake_minimum_required( VERSION 2.6)
project (ChatServer)

# The version number.
set (ChatServer_VERSION_MAJOR 1)
set (ChatServer_VERSION_MINOR 0)


# Add the executable
add_executable(ChatServer main.cpp)

#Install the product
install (TARGETS ChatServer DESTINATION ChatServer/bin)
