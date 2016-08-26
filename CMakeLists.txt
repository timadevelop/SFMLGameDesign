cmake_minimum_required(VERSION 3.5)
project(Game)

if(WIN32)
	set(SFML_ROOT "path/to/SFML^2.3")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ./utilities/ResourceHolder.hpp ./utilities/ResourceHolder.inl ./utilities/StringHelpers.hpp ./entities/Entity.cpp ./entities/Entity.h ./entities/Aircraft.cpp ./entities/Aircraft.h ./nodes/SceneNode.cpp ./nodes/SceneNode.h ./nodes/SpriteNode.cpp ./nodes/SpriteNode.h ./logic/World.cpp ./logic/World.h ./commands/Command.cpp ./commands/Command.h ./commands/Category.cpp ./commands/Category.h ./commands/CommandQueue.cpp ./commands/CommandQueue.h ./entities/Player.cpp ./entities/Player.h states/StateStack.cpp states/StateStack.h states/State.cpp states/State.h states/StateIdentifiers.h Application.cpp Application.h states/GameState.cpp states/GameState.h states/TitleState.cpp states/TitleState.h utilities/Utility.inl utilities/Utility.h states/MenuState.cpp states/MenuState.h states/PauseState.cpp states/PauseState.h states/ParallelTask.cpp states/ParallelTask.h states/LoadingState.cpp states/LoadingState.h utilities/ResourceIdentifiers.h)
add_executable(Game ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES})
endif()

include_directories(.)
