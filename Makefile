CC = gcc
CFLAGS = `pkg-config -cflags gtk+-3.0` `pkg-config -libs gtk+-3.0`

objects = src/main.o src/sp-application.o

src/simple_gallery: $(objects)
	$(CC) $(CFLAGS) $(objects) -o simple_gallery

src/main.o: src/main.c 
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/sp-application.o: src/sp-application.c src/sp-application.h
	$(CC) $(CFLAGS) -c src/sp-application.c -o src/sp-application.o

clean:
	rm simple_gallery $(objects)

