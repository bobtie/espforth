# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(espforth)


set(FS_BUILD_DIR "${CMAKE_BINARY_DIR}/fs_staging")

file(MAKE_DIRECTORY "${FS_BUILD_DIR}")

file(COPY_FILE "samples/7segs_demo.fs" "${FS_BUILD_DIR}/boot.fs")

fatfs_create_spiflash_image(storage ${FS_BUILD_DIR} FLASH_IN_PROJECT)
