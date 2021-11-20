# Game of Life Visualizer
This is a small application that simulates John Conway's famous mathematical zero player game / thought experiement.  

The goal of this project is to have a simulator that can allow the user to create and load intial states for the Game of Life and see the outcomes.  

As the project grows I will expand this documentation.  There will be some lag as I tend to have the habit of delaying writing to docs in my personal programming until I am satisfied with a feature and plan to keep it.



## Installation

Nothing currently implemented yet.

## Dependencies


Go 1.16
Gcc 10.3.0


## Tech Stack

I will be using Go and C to implement this application.  These low level languages will ensure performance for the simulator even if additional features are added on.  I choose these two rather than others (or just one itself) mainly just to get practice in both those langauges specifically.  

To get into specifics, I chose to use C for the GUI of this application, as the C ecosystem just had way better and more documented options.  Many GUI Go libaries were just not well supported.  

For now, Go will run everything else, although as I add features I do expect once again to run into situations where C is the better option because of library support.

## Bugs

None listed yet

