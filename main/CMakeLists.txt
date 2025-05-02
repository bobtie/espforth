idf_component_register(SRCS "espforth.c" INCLUDE_DIRS ".")

idf_build_set_property(COMPILE_OPTIONS "-Desp32" APPEND)
