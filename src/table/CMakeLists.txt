file(GLOB_RECURSE table_src *.cpp)
add_library(table_lib STATIC "${TABLE_HEADERS}" "${table_src}")
