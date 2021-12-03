

build:


run:



c_run:
	cd src && gcc life.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o life.out
	cd src && ./life.out


c_build:
	cd src && gcc life.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o draw.out
