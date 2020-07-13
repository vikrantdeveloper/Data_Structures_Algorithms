add_library(
    inc 
    commondefine.h
    headerfiles.h
    main.h
    linkedlist.h
    sorting.h
)
set_target_properties(inc PROPERTIES LINKER_LANGUAGE C)
target_include_directories(inc PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")