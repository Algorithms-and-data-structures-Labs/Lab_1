file(GLOB_RECURSE list_headers List/*.h List/*.hpp)
set(LIST_HEADERS "${list_headers}" PARENT_SCOPE)

file(GLOB_RECURSE polinom_headers Polinom/*.h Polinom/*.hpp)
set(POLINOM_HEADERS "${polinom_headers}" PARENT_SCOPE)

file(GLOB_RECURSE stack_headers Stack/*.h Stack/*.hpp)
set(STACK_HEADERS "${stack_headers}" PARENT_SCOPE)
