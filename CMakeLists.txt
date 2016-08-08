cmake_minimum_required(VERSION 3.5)
project(Game)

if(WIN32)
	set(SFML_ROOT "path/to/SFML^2.3")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.h Game.cpp ResourceHolder.hpp ResourceHolder.inl StringHelpers.hpp Entity.cpp Entity.h Aircraft.cpp Aircraft.h SceneNode.cpp SceneNode.h)
add_executable(Game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES})
endif()

include_directories(.)