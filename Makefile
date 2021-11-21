

build:


run:



c_run:
	cd internal/gui && rm *.out
	gcc gtkTest.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
	./a.out


c_build:
	gcc gtkTest.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
