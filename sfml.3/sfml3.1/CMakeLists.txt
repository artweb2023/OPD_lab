add_executable(01 main.cpp)

# Настройка пути к компилятору LLVM/Clang
set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")

# Настройка стандарта C++ (C++17 в данном случае)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)


target_include_directories(01 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(01 PUBLIC cxx_std_17)
target_compile_definitions(01 PRIVATE SFML_STATIC)

target_link_libraries(01 PRIVATE sfml-graphics)
