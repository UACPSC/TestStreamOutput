# @file CMakeLists.txt
# 
# CMake files for testStreamOutput

cmake_minimum_required(VERSION 3.29)

# project info
project(testStreamOutput)

# processOrder()
add_executable(testStreamOutput testStreamOutput.cpp)
target_compile_features(testStreamOutput PRIVATE cxx_std_17)
target_compile_options(testStreamOutput PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-pedantic;-Werror>
)

# Run test program
add_custom_target(test COMMENT "Test Stream Output"
                       COMMAND $<TARGET_FILE:testStreamOutput>
                       DEPENDS testStreamOutput)
