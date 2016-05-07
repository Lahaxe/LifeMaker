find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${Qt5Widgets_INCLUDES})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_definitions(-DBOOST_FILESYSTEM_VERSION=3)
add_definitions(-DHAVE_CONFIG_H)

file(GLOB_RECURSE files "*.cpp")
add_library(liblifemaker SHARED ${files})

set_target_properties(liblifemaker PROPERTIES OUTPUT_NAME lifemaker)
target_link_libraries(liblifemaker ${Qt5Widgets_LIBRARIES})

