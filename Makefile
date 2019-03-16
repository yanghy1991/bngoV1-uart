CFLAGS= -Wall -O2
CC=mips-linux-gnu-gcc
deps= SerDrive.h get_time.h ws2812.h msq_send.h io_busy.h bottom_led.h ir.h ir_device.h
obj += main.o SerDrive.o get_time.o ws2812.o msq_send.o io_busy.o bottom_led.o ir_device.o
TARGET = uart
uart: $(obj)
		$(CC) $(CFLAGS) -o $(TARGET) $(obj) -lpthread -lir_control

%.o: %.c $(deps)
		$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(TARGET) $(obj)
