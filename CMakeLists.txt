cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# ---- Project ----

project(catch2_example LANGUAGES CXX)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

CPMAddPackage(
  NAME tribonacci
  GITHUB_REPOSITORY sthagen/cpp-tribonacci
  GIT_TAG 97f0f2664530d03f504c00875361096790b46dc8
)
CPMAddPackage(
  NAME catch2
  GITHUB_REPOSITORY catchorg/Catch2
  VERSION 2.13.4
)

# ---- Create binary ----

add_executable(catch2_example main.cpp)
target_link_libraries(catch2_example tribonacci Catch2)
set_target_properties(catch2_example PROPERTIES CXX_STANDARD 17)

# ---- Enable testing ----

enable_testing() 
add_test(catch2_example catch2_example)
