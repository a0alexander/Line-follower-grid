# Line-follower-grid
Grid based line follower designed for Praxis Project - Originally developed in Nov.2017 | Posted in 2020

When traversing the grid the robot uses an array of IR sensors to detect the black lines on the white surface. The robot follows a straight path on the grid until it meets
a region where all IR sensors register a single color. This means it has reached the end of the length of the grid. During this stage the robot proceeds to make a 90deg turn
until it re-registers a value. It follows this path until it meets the next corner and continues. 

Comments : The code is rather primitive and works based on if statements defining what action the robot should take for predined scenarios where the sensors are lit or not. Eg:
0 0 1 1 1 0 0 <- This sequence would tell the robot to move forward straight. A better approach to this problem would be to use PID but at that time it had not yet been introduced.

Includes bluetooth2.ino file which was created not part of the project but more because of curiosity and for fun. This allows the robot to be controlled via bluetooth from an phone and the HC-05 bluetooth module. At the time developing a remote controlled rover was quite considerable. 

