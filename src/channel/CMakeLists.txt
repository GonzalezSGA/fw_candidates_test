add_library(channel STATIC rs485.c protocol.c)
target_include_directories(channel PUBLIC .)