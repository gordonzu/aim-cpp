project(aicpp)
cmake_minimum_required(VERSION 2.6)

include_directories("/home/gordonzu/.local/googletest-release-1.8.0/googlemock/include"
                    "/home/gordonzu/.local/googletest-release-1.8.0/googletest/include"
                    "/home/gordonzu/src/cpp/AICPP/src")
link_directories   ("/home/gordonzu/.local/googletest-release-1.8.0/mybuild/googlemock"
                    "/home/gordonzu/.local/googletest-release-1.8.0/mybuild/googlemock/gtest")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -ggdb3 -Wall -Wno-unused-variable -O0 -fmax-errors=1")

set(
    sources
    main.cpp
    src/agent/dynamic_object.cpp

    src/environment/environment.cpp
    src/environment/xyenv/xy_environment.cpp
    src/environment/xyenv/xy_environment_state.cpp
    src/agent/action.cpp
    src/agent/agent_programs/agent_program.cpp
    src/util/datastructure/xy_location.cpp
    src/util/algorithm/utils.cpp
    src/util/datastructure/table.cpp
    ##################################################
    # tests 
    ##################################################
    test/dynamic_percept_test.cpp

    test/simple_rule_test.cpp
    test/percept_sequence_test.cpp
    test/table_test.cpp
    test/xy_environment_test.cpp
    test/tabledriven_agent_program_test.cpp
   )

add_executable(aicpp ${sources})
target_link_libraries(aicpp gmock)
target_link_libraries(aicpp gtest)
target_link_libraries(aicpp pthread)

add_custom_command(TARGET aicpp
                 POST_BUILD
                 COMMAND "make")

add_custom_command(TARGET aicpp
                 POST_BUILD
#                COMMAND valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./aicpp)
#                COMMAND valgrind --tool=memcheck --leak-check=yes ./aicpp)
                 COMMAND ./aicpp)

