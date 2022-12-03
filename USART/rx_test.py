#!/usr/bin/python3 
""" 
Copyright  (c), 2022 Umar <jUmarB@protonmail.com> @OpenwireLab 
"""
sys        = __import__("sys") 
t          = __import__("time")

try  : 
    io_serial  = __import__("serial")
except  ImportError  :  
    import pip 
    pip.main(["install" , "pyserial"]) 

    

BAUD = 9600  
SDIV = "/dev/ttyUSB0" 

def  kbint  (main)  : 
    def ctlr_c ()  : 
        try : 
            main() 
        except KeyboardInterrupt :  
            sys.stdout.write("End Transmission\n") 
            sys.exit(2) 
    return  ctlr_c  

@kbint
def  main () ->  int  : 
    
    sys.stdout.write("Ctrl ^C to exit\n") 
    while  True   : 
        ios = io_serial.Serial(SDIV , BAUD) 
        ios.write(b'a')  
        ios.close() 
        t.sleep(2) 

    return 0 

if __name__.__eq__("__main__") : 
    main.__call__()  
