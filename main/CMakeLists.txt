add_executable(lnxespforth espforth_i.c)
target_compile_options(lnxespforth PUBLIC -g)

configure_file(${CMAKE_SOURCE_DIR}/samples/myboot.fs ${CMAKE_BINARY_DIR}/main/boot.fs COPYONLY)
