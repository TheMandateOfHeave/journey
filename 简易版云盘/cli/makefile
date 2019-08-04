all: ser

ser: ser.o work_thread2.o
	gcc -o ser ser.o work_thread2.o -lpthread

ser.o: ser.c
	gcc -c ser.c

work_thread.o: work_thread2.c
	gcc -c work_thread2.c

clean:
	rm -f *.o ser
