file(GLOB_RECURSE list_headers list/*.h list/*.hpp)
set(LIST_HEADERS "${list_headers}" PARENT_SCOPE)

file(GLOB_RECURSE polinom_headers polinom/*.h polinom/*.hpp)
set(POLINOM_HEADERS "${polinom_headers}" PARENT_SCOPE)

file(GLOB_RECURSE stack_headers stack/*.h stack/*.hpp)
set(STACK_HEADERS "${stack_headers}" PARENT_SCOPE)

file(GLOB_RECURSE table_headers table/*.h table/*.hpp)
set(TABLE_HEADERS "${table_headers}" PARENT_SCOPE)

