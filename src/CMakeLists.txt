set(SOURCES "main.c" "linkedlist.c")

add_executable(core ${SOURCES})
set_target_properties(core PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(core PRIVATE inc)