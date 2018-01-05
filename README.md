# Rubik's 2x2 Cube Solver
Program that outputs a solution to a 2x2 Cube given an input configuration

The goal of this project was to create a program that accepts as an input the current state of a 2x2 Rubik's Cube ("Pocket Cube"), and outputs a step-by-step Beginner's Method solution of that cube, in order to guide the user through solving it using the Beginner's Method. The program contains 7 total files -- 3 header/cpp pairs and the runner file.

TO COMPILE: make
TO RUN: ./solver

**Inputting the cube state**

There are 3,674,140 possible positions that a 2x2 Rubik's cube can be in, meaning it would be infeasible for the solver to have an algorithm saved for every possible combination. Therefore, the program keeps a working virtual cube in order to check the current state of the user's cube and make sure that cube turns execute as intended. The virtual cube is implemented using 3 classes: Cube, Side, and Row. The Cube class contains 6 Side objects corresponding to each side of the cube, which in turn each contain two Row objects corresponding to the upper and lower rows. Each Row object contains two integer members, a left and a right cubie (individual squares on the cube). Using all of these as well as supporting functions which compute the result of any permutations done on a side (clockwise turn, counter-clockwise turn, or double turn), the program is able to keep a virtual cube which, ideally, mirrors the user's cube. When inputting a cube state, the user is presented with a visual aid and is asked for the color of each individual cubie. These can be inputted by typing 'r' for red, 'w' for white, 'b' for blue, 'g' for green, 'o' for orange, and 'y' for yellow. The user will be allowed the chance to confirm that the entered cube state is correct before proceeding.

**Notation**

The notation commonly used for Rubik's Cube algorithms is as follows: F corresponds to the front side, B to the back side, L to the left side, R to the right side, U to the up side, and D to the down side, with regards to how the user is holding the cube. Turns are assumed to be clockwise by default (F is a clockwise turn of the front side/face), but a counter-clockwise turn is denoted by a ' (prime). Likewise, a double-turn is denoted by a 2 (it does not matter which direction the user turns in). For example, a clockwise turn of the front face followed by a counter-clockwise turn of the front face followed by two turns of the front face would be written as F F' F2. This is the notation used in this program. It's important to keep in mind which direction is clockwise -- R corresponds to a downward turn on the right side as viewed from the front face, but L corresponds to an upward turn on the left side as viewed from the front face. Since these mistakes are easy to make, the program displays the current state the cube should be in along the way, so that the user can compare their cube to prevent any mistakes.

**Calculating the solution**

The program calculates the solution in 3 main steps: solving the first layer, orienting the last layer, and solving the last layer. In the first step, I chose to solve the white face on the upper face first to keep it simple. The "middle layer" has to be aligned in this order (going left to right): red, blue, orange, green. Again I chose to make the front face red, which means that the rest of the sides will be solved according to this pattern. This step is mostly intuitive, so the algorithms here were ones I typically use that can be applied to many permutations while solving the first layer. The second step consists of determining which of the 7 possible states the cube is in and using the corresponding algorithm to solve the yellow face (these states and algorithms can be found here: http://www.cubewhiz.com/ortegaoll.php). Similarly, the third step involves determining which of the 2 possible states the cube is in and using the corresponding algorithm to solve the middle layers, effectively solving the entire cube (states and algorithms available here: http://www.cubewhiz.com/ortegapbl.php).

**Accuracy**

To test the algorithm's accuracy I included a test bench function in solver.cpp which randomly generates and solves 1000 cubes, taking note if an exception was thrown or if a cube ends up not being completely solved. The cubes were each generated by starting from a solved cube and performing anywhere from 10 to 40 random turns on the cube. At the end of running the test bench, the program displays the number of tests passed, the average time taken to generate each solution, and the maximum time taken to generate a single solution.

**Thoughts**

The solutions generated aren't even close to the fastest solutions possible (any 2x2 cube can actually be solved in only 11 or fewer turns), but the program reliably solves the cube every time, and makes the steps distinct and reasonably easy to follow. In terms of the code, I realize that some of the algorithms were probably unnecessarily convoluted, mostly due to the initial framework of how the program stores the virtual cube (keeping the entire cube as an integer value or a vector for example would've significantly increased runtime efficiency). However, it still computes solutions in around 70 milliseconds on average, which is fast enough to not be noticeable by the user.
