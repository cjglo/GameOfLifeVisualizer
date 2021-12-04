
run:
	cd src && gcc life.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o draw.out
	cd src && ./life.out


build:
	cd src && gcc life.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o draw.out
