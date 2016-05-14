
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

add_definitions(-DBOOST_FILESYSTEM_VERSION=3)
add_definitions(-DHAVE_CONFIG_H)
add_definitions(-DUSE_LOG4CPP)

file(GLOB_RECURSE files "*.cpp")
add_library(liblifemaker SHARED ${files})

set_target_properties(liblifemaker PROPERTIES OUTPUT_NAME lifemaker)
target_link_libraries(liblifemaker log4cpp)
