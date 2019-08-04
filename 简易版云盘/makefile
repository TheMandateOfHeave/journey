all: ser

ser: ser.o work_thread2.o
	gcc -g -o  ser ser.o work_thread2.o -lpthread

ser.o: ser.c
	gcc -c ser.c -o ser.o -g

work_thread.o: work_thread2.c
	gcc -c work_thread2.c -o work_thread2.o -g

clean:
	rm -f *.o ser
