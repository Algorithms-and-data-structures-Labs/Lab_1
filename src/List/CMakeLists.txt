file(GLOB_RECURSE list_src *.cpp)
add_library(list_lib STATIC "${LIST_HEADERS}" "${list_src}")
