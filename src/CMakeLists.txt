add_library(autoid STATIC autoid.c)
add_subdirectory(channel)
target_link_libraries(autoid channel)
target_include_directories(autoid PUBLIC .)