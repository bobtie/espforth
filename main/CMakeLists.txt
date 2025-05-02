if(COMPILE_LINUX_VERSION)
add_executable(lnxespforth espforth_i.c)
target_compile_options(lnxespforth PUBLIC -g)
else()
idf_component_register(SRCS "espforth.c" INCLUDE_DIRS ".")
endif()

# configure_file(${CMAKE_SOURCE_DIR}/samples/myboot.fs ${CMAKE_BINARY_DIR}/main/boot.fs COPYONLY)
