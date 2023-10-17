add_executable(02 main.cpp)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)


target_include_directories(02 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(02 PUBLIC cxx_std_17)
target_compile_definitions(02 PRIVATE SFML_STATIC)

target_link_libraries(02 PRIVATE sfml-graphics)
