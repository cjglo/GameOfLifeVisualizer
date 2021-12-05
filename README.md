# Game of Life Visualizer
This is a small application that simulates John Conway's famous mathematical zero player game / thought experiement.  

The goal of this project is to have a simulator that can allow the user to create and load intial states for the Game of Life and see the outcomes.  

As the project grows I will expand this documentation.  There will be some lag as I tend to have the habit of delaying writing to docs in my personal programming until I am satisfied with a feature and plan to keep it.

## Installation

Currently I have not written any scripts, so installation remains the same as compiling the program yourself from my source code.

Make sure the dependecnies are installed then run the Makefile commands yourself or copy the gcc compiler command and run it while in the directory of the `life.c` file.

## Dependencies

#### Compilers

gcc 10.3.0

#### Libaries and Other

GTK (libgtk-3-0)
pkg-config 0.29.1+

## Tech Stack

I will be C to implement this application.  I choose it rather than others (or higher-level languages that would have worked just as well) mainly just to get practice in C specifically.  Although since it is implemented in such a low level, performance should be good even with any additional features added on.

To get into specifics, I chose GTK as the libary for the GUI because of my familiarity with a very similar Java libary.  

At one point I was considering adding Go just for more practice.  For now I can't think of a real reason to add it that would make sense, but it is possible something may be implemented in Go in the future.

## Bugs

None listed yet

