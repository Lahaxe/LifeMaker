find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/)

link_directories(${Boost_LIBRARY_DIRS})

add_definitions(-DHAVE_CONFIG_H)
add_definitions(-DBOOST_TEST_DYN_LINK)
add_definitions(-DUSE_LOG4CPP)

file(GLOB_RECURSE tests *.cpp)
foreach(test_file ${tests})
    get_filename_component(test ${test_file} NAME_WE)
    add_executable(${test} ${test_file})
    target_link_libraries(${test} liblifemaker ${Boost_LIBRARIES})
    file(READ ${test_file} content)
    
    set(pattern "BOOST_(AUTO|FIXTURE)_TEST_CASE\\(([^),]+)")
    
    string(REGEX MATCHALL ${pattern} cases ${content})
    
    foreach(case ${cases})
        string(REGEX REPLACE ${pattern} "\\2" case ${case})
        add_test("${test}_${case}" "${test}" "--run_test=${case}")
    endforeach()
endforeach()
