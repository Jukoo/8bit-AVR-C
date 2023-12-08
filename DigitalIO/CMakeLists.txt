cmake_minimum_required(VERSION 3.25)  
project(pushbtn) 

include(../config.cmake) 

add_definitions(-DF_CPU=${CLK_CYCL} -mmcu=${MMCU_TARGET} )
add_executable(${PROJECT_NAME} main.c)

conv2hex(${PROJECT_NAME}) 
flash_mcu(${PROJECT_NAME}) 
