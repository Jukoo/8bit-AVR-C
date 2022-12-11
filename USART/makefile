
cc  = avr-gcc   
board=atmega328p 
hardware_platform=arduino 
CLK_CYCL:=16000000UL
header_location:=./include  
sharedLib_location=../sharedLib/
cflags = -Wall -Wextra -O2  -mmcu=$(board) -DF_CPU=$(CLK_CYCL)  -I $(header_location) 
SRC=$(wildcard *.c ) 
sourcefile:=
OBJ=$(SRC:.c=.o) 
exec =avrusartxrx.elf

io_serial?= 
ifeq ($(shell  uname -s) ,Linux) 
	io_serial=/dev/ttyUSB0  
endif 
# for arduino nano 
# add  -b 57600 
# ex : make type=nano 
type:=
fbaud:= 
ifeq ($(type) ,nano) 
	fbaud= -b 57600 
endif


all : $(exec) 


$(exec)  : ${OBJ} 
	@echo -e " AVR LD "
	$(cc) -o $@ $^ $(cflags)  

shared_object :  $(sourcefile)   
	@echo  -e "SHARED OBJ" 
	$(cc)  -o  $(sharedLib_location)lib$(exec:.elf=.so)  -fpic -shared  $(sourcefile)  $(cflags) 

%.o :  %.c 
	@echo -e "AVR CC "
	$(cc) -c $< -o $@  $(cflags) 

.PHONY : clean  mproper   ihex  flash 

ihex  : $(exec) 
	@echo -e "AVR INTEL HEX" 
	avr-objcopy  -O  ihex  -R -eeprom  $^  $(exec:.elf=.hex) 

flash :  ihex 
	@echo -e "AVR FLASH "
	avrdude  -F -v  -c $(hardware_platform)   -P $(io_serial)   -p $(board) $(fbaud)    -U flash:w:$(exec:.elf=.hex) 


clean : 
	@echo  -e "CLS " 
	rm *.o *.hex 

mproper : clean 
	@echo -e "ERASE BASE"
	rm *.elf
