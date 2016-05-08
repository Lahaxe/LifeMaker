find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE files "*.cpp")
file(GLOB_RECURSE files_HEADERS "*.h")
file(GLOB_RECURSE files_FORMS "*.ui")
file(GLOB_RECURSE files_RESOURCES "*.qrc")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR}
                    ${Qt5Widgets_INCLUDES})

qt5_wrap_cpp(files_HEADERS_MOC ${files_HEADERS})
qt5_wrap_ui(files_FORMS_HEADERS ${files_FORMS})
qt5_add_resources(files_RESOURCES_RCC ${files_RESOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_definitions(-DBOOST_FILESYSTEM_VERSION=3)
add_definitions(-DHAVE_CONFIG_H)

add_library(liblifemakergui SHARED ${files}
                                   ${files_HEADERS_MOC}
                                   ${files_FORMS_HEADERS}
                                   ${files_RESOURCES_RCC})

set_target_properties(liblifemakergui PROPERTIES OUTPUT_NAME lifemakergui)
target_link_libraries(liblifemakergui liblifemaker ${Qt5Widgets_LIBRARIES})

