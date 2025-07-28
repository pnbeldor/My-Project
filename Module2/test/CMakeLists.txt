if(BUILD_TESTING)
    add_executable(Module2Tests Module2_test.cpp)

   
    #target_link_libraries(Module2_tests PRIVATE GTest::gtest_main)

    target_link_libraries(Module2Tests PUBLIC gtest GTest::gtest_main)
    #target_link_libraries(M2Tests PUBLIC NearlyMath gtest GTest::gtest_main)
    #target_link_directories(NearlyMathTest PUBLIC ../src)
    target_include_directories(Module2Tests PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

    add_test(NAME M2Tests COMMAND Module2Tests)
    include(GoogleTest)
endif()
