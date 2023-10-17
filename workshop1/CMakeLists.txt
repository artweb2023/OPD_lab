# Минимальная версия CMake: 3.8
cmake_minimum_required(VERSION 3.8)

# Имя проекта: sfml-lab-4
project(cpp-samples)

# Настройка пути к компилятору LLVM/Clang
set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")

# Настройка стандарта C++ (C++17 в данном случае)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Имя директории
add_subdirectory(workshop1.1)
add_subdirectory(workshop1.2)
add_subdirectory(workshop1.3)





