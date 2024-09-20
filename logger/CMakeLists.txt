cmake_minimum_required(VERSION 3.20)
project(logger_lib)

add_library(logger_lib SHARED src/logger.cpp)

target_compile_definitions(logger_lib PRIVATE
LOGGER_FUNCTIONS_EXPORTS)

target_include_directories(logger_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS logger_lib
LIBRARY DESTINATION "${CMAKE_BINARY_DIR}"
RUNTIME DESTINATION "${CMAKE_BINARY_DIR}"
ARCHIVE DESTINATION "${CMAKE_BINARY_DIR}"
)
install(FILES include/logger.h DESTINATION
"${CMAKE_CURRENT_SOURCE_DIR}/include")