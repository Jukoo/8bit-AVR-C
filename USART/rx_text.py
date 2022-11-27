""" 
Copyright  (c), 2022 Umar <jUmarB@protonmail.com> @OpenwireLab 
"""
sys        = __import__("sys") 
io_serial  = __import__("serial")
t          = __import__("time")

BAUD = 9600  
SDIV = "/dev/ttyUSB0" 

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
