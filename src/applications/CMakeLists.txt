find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../
                    ${CMAKE_CURRENT_SOURCE_DIR}/../lifemaker
                    ${Qt5Widgets_INCLUDES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_definitions(-DUSE_LOG4CPP)

add_executable(LifeMaker "lifemaker.cpp")
target_link_libraries(LifeMaker liblifemaker liblifemakergui ${Qt5Widgets_LIBRARIES})

add_executable(merge_elements "merge_elements.cpp")
target_link_libraries(merge_elements liblifemaker)
