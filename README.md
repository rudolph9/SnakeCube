# Snake Cube
Recently, one of our engineers introduced us to the snake cube. A snake cube is a puzzle composed of a chain of cubelets, connected by an elastic band running through each cubelet. Each cubelets can rotate 360°about the elastic band, allowing various structures to be built depending upon the way in which the chain is initially constructed, with the ultimate goal of arranging the cubes in such a way to create a cube.

Consider the 27-cubelet snake, which assembles into a 3*3*3 cube, shown below.

This particular arrangement contains 17 groups of cubelets, composed of 8 groups of two cubelets and 9 groups of three cubelets. This arrangement can be expressed in a variety of ways, but for the purposes of this exercise, let ’0′ denote a pieces whose rotation does not change the orientation of the puzzle, or may be considered a “straight” piece, while ’1′ will denote pieces whose rotation changes the puzzle configuration, or “bend” the snake. Using that schema, the snake puzzle above could be described as

001110110111010111101010100

Your challenge is to write a program, in any language of your choosing, that takes the cube dimensions (X, Y, Z) and a binary string as input, and outputs ’1′ (without quotes) if it is possible to solve the puzzle, i.e. construct a proper X*Y*Z cube given the cubelet orientation, and ’0′ if the current arrangement cannot be solved.

snake_cube_solution(3, 3, 3, “001110110111010111101010100″) == 1

Bonus points are given for printing out the final x,y,z coordinates for each cubelet, in order, assuming that the first block of the cube always begins at (1,1,1) and the final cubelet always ends with (X,Y,Z).

## Running the test cases

Using Ruby 1.9.3 and after installing rspec (`$ gem install rspec`);

    $ rspec snake_cube_spec.rb

