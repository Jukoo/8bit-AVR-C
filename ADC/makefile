

cc  = avr-gcc  
cflags = -Wall -Wextra -O2  -mmcu=atmega328p -DF_CPU=16000000UL   
SRC=$(wildcard *.c ) 
OBJ=$(SRC:.c=.o) 
exec =a2dc.elf 

all : $(exec) 


$(exec)  : ${OBJ} 
	@echo -e " AVR LD "
	$(cc) -o $@ $^ $(cflags)  


%.o :  %.c 
	@echo -e "AVR CC "
	$(cc) -c $< -o $@  $(cflags) 

.PHONY : clean  mproper   ihex  flash 

ihex  : $(exec) 
	@echo -e "AVR INTEL HEX" 
	avr-objcopy  -O  ihex  -R -eeprom  $^  $(exec:.elf=.hex) 

flash :  ihex 
	@echo -e "AVR FLASH "
	avrdude  -F -v  -c arduino  -P /dev/ttyUSB0  -p atmega328p   -U flash:w:$(exec:.elf=.hex) 


clean : 
	@echo  -e "CLS " 
	rm *.o *.hex 

mproper : clean 
	@echo -e "ERASE BASE"
	rm *.elf
