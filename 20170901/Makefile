CFLAGS= -Wall -O2
CC=mips-linux-gnu-gcc
#deps= io_busy.h d_tupe.h
obj += main.o SerDrive.o
TARGET = uart
tupe: $(obj)
		$(CC) $(CFLAGS) -o $(TARGET) $(obj)

%.o: %.c $(deps)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(obj)
