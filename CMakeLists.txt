cmake_minimum_required(VERSION 2.8)	 

project(calcul)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB funct.cpp speaking.cpp)			

add_library(my_lib STATIC ${SOURCE_LIB})	
add_executable(calcul ${SOURCE_EXE})	

target_link_libraries(calcul my_lib)
