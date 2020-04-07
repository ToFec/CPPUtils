cmake_minimum_required(VERSION 3.5)
project(CPPUtils)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

find_path(NRRD_INCLUDE_DIR NAMES NRRD/nrrd.hxx)
message("NRRD include dir = ${NRRD_INCLUDE_DIR}")
include_directories(${NRRD_INCLUDE_DIR})

add_library(CPPUtils Utils.cxx Image.h ImageFactory.cpp ImageFactory.h ImageWrapper.h Utils.h)
target_include_directories (CPPUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install (TARGETS CPPUtils EXPORT CPPUtilsTargets DESTINATION "${Project_BINARY_DIR}/lib")
install (FILES Image.h Utils.h ImageFactory.h ImageWrapper.h DESTINATION "${Project_BINARY_DIR}/include")

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "CPPUtilsConfigVersion.cmake" COMPATIBILITY SameMajorVersion VERSION 3.5
)

configure_package_config_file(
    "cmake/Config.cmake.in"
    "CPPUtilsConfig.cmake"
    INSTALL_DESTINATION "${Project_BINARY_DIR}"
)


