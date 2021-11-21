include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(..)

add_executable(testDSA TestLinkedList.cpp)
target_link_libraries(testDSA gtest gtest_main)
add_test(NAME test COMMAND testDSA)