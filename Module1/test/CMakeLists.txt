if(BUILD_TESTING)
    add_executable(myTest Test1_test.cpp)
    add_executable(NearlyMathTest NearlyMath_tests.cpp)

    #add_subdirectory(${CMAKE_BINARY_DIR}/googletest)
    
    target_link_libraries(myTest PUBLIC gtest GTest::gtest_main)
    target_link_libraries(NearlyMathTest PUBLIC NearlyMath gtest GTest::gtest_main)
    #target_link_directories(NearlyMathTest PUBLIC ../src)
target_include_directories(NearlyMathTest PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
    #add_test(NAME M1_MyTest COMMAND myTest)
    #add_test(NAME M1_NearlyMathTest COMMAND NealyMathTest)
    include(GoogleTest)
endif()
