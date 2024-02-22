file(GLOB_RECURSE stack_src *.cpp)
add_library(stack_lib STATIC "${STACK_HEADERS}" "${stack_src}")
