cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(Matrix VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置编译选项
if(MSVC)
    # Windows (Visual Studio)
    add_compile_options(/W4)
else()
    # Linux/macOS (GCC/Clang)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 添加库文件（矩阵类）
add_library(matrix_lib
    matrix.cpp
    matrix.hpp
)

# 添加可执行文件（主程序）
add_executable(matrix_test
    main.cpp
)

# 链接库到可执行文件
target_link_libraries(matrix_test PRIVATE matrix_lib)

# 设置输出目录
set_target_properties(matrix_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# 安装规则（可选）
install(TARGETS matrix_test
    RUNTIME DESTINATION bin
)

install(FILES matrix.hpp
    DESTINATION include
)

# 打印配置信息
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

