
run:
	cd src && gcc life.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o game.out
	cd src && ./game.out


build:
	cd src && gcc life.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o game.out
