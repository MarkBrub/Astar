# A*
A* for SMU summer camp

As part of a SMU summer camp I led, I made a program that could input a picture and solve a maze in the picture given a start and end location. I used the A* pathfinding algorithm combined with the OpenCV vision processing library to identify and solve the maze. All of the code for the A* algrithm was written by me.

I followed this tutorial to set up OpenCV with Visual Studio 2019:
https://www.deciphertechnic.com/install-opencv-with-visual-studio/

I follwed the sudo code on the A* Wikipedia page to write the algorithm:
https://en.wikipedia.org/wiki/A*_search_algorithm

This program is meant to take in a picture of a masking tape path or maze on a dark floor and output both a picture of the maze solved and a file containing the list of direction to take from the start node to the end node. For some reason the image is a different orentation than the one used to generate the path.

![The initial picture of the path](/Images/path.png)

The result is a modified picture that has just the desired path from the initial image. In the result the wall nodes are light gray, explored nodes are dark grey, the start node is green, the end node is red, and the path is blue.

![Solved path](/Images/solvedPath.png)

The program also output a text file with a list of directions and durationsto get from the start to the end node. The directions are represented as numbers 0-7 and a key can be found in /Lyle/direction.hpp. An example output can be found in /Lyle/output.txt.

As this example is realtivly simple and the program can work on any picture with a dark and light path here is a better example of the algorithm working. Becasue the walls of the maze are so thin the blur is removed in the image processing step as it deforms the image.

![Solved maze](/Images/solvedMaze.png)
