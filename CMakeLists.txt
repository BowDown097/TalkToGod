project(TalkToGod)
set(CMAKE_CXX_FLAGS "-O0") # Optimizations interfere with our ability to speak with God
add_executable(TalkToGod god.c god.h main.c)
