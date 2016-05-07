find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../
                    ${Qt5Widgets_INCLUDES})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(LifeMaker "lifemaker.cpp")
target_link_libraries(LifeMaker liblifemakergui ${Qt5Widgets_LIBRARIES})
