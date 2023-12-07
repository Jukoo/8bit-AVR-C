message(CHECK_START  "Checking Requirement") 

set(CMAKE_C_COMPILER avr-gcc)     #avr-gcc toolchain 
set(HEXtension  hex)              #default extension file   
set(MMCU_TARGET  atmega328p)      #default mcu target 
set(PLATFORM  arduino)            #default platform 
set(CLK_CYCL  16000000UL)         #default clock 
set(SERIAL    /dev/ttyUSB0)       #default SERIAL device 
set(FORMAT_TARGET   ihex)         #default format 


option(VERBOSE_MODE "Verbose mode when flashing ... " OFF)
set(Verbose)
if(VERBOSE_MODE) 
  message(STATUS "enable verbose mode")
  set(Verbose -v)  
endif() 


function(conv2hex   project_name) 
  add_custom_target(convtohex ALL 
    COMMAND   avr-objcopy -O  ${FORMAT_TARGET} -R -eeprom   ${CMAKE_BINARY_DIR}/${project_name} ${CMAKE_BINARY_DIR}/${project_name}.${HEXtension} 
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} 
    COMMENT "build Hex"
  ) 
endfunction() 

function(flash_mcu project_name)
  add_custom_target(flash  ALL  
    COMMAND  avrdude -FV  ${Verbose} -c ${PLATFORM}  -p ${MMCU_TARGET} -P ${SERIAL}
    -U flash:w:${CMAKE_BINARY_DIR}/${project_name}.${HEXtension} 

     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} 
     COMMENT "Flashing ${MMCU_TARGET}"
     VERBATIM) 
endfunction() 
