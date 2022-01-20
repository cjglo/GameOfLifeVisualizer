# Game of Life Visualizer
This is a small application that simulates John Conway's famous mathematical zero player game / thought experiement.  

This program works similar to online simulators of Life, it allows a selection of squares and then confirms the inital state.  

The project currently is in a beta version.  It's basic mechanics work, but I will be adding many more features in the future.  I will likely take a short break to focus on some other projects but will be back soon!

## Installation & Running Visualizer

Make sure to have the dependencies installed, then git clone this repository.

Navigate to the root of the directory (same directory this README is) in the command line and type `make run`.  That will compile and run the program.

## Dependencies

#### Compilers

gcc 10.3.0

#### Libaries and Other

GTK (libgtk-3-0)
pkg-config 0.29.1+

## Instructions of Visualizer

Very basic as of now, click on the screen to select the "live" cells which will be colored in white.  (There will be a slight delay as I have the GTK drawer updating only a few times a second, simply because when the simulation occurs it is nice to have a delay between changing states).

Click the space bar to begin the simulation and close the window to exit the program. 

There is currently no "reset" feature, since the program builds and runs quickly, but I will fix this in the future.

## Tech Stack

I will be C to implement this application.  I choose it rather than others (or higher-level languages that would have worked just as well) mainly just to get practice in C specifically.  Although since it is implemented in such a low level, performance should be good even with any additional features added on.

To get into specifics, I chose GTK as the libary for the GUI because of my familiarity with a very similar Java libary.  

At one point I was considering adding Go just for more practice.  For now I can't think of a real reason to add it that would make sense, but it is possible something may be implemented in Go in the future.

## Bugs

None listed yet

