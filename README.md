# Pong-Game

The project is a console Pong Game written in C++ using classes, methods, for loops, while loops and also swtich statements.
The paddles are made from the "\xDB" character and the borders from the "\xB2" character.
The controls for the left paddle are "W" and "S" and for the right paddle are "o" and "l". If you want different controls just change the 156-159 lines to your preference.

I chose to structure the code into 3 main classes: cBall, cPaddle and cGameManager.
The cBall class contains methods for its movement using the enumerator direction which dictates if the ball should go: left, upleft, downleft, right, upright,downright.
The cPaddle class is used for creating the two paddles in the cGameManager class. The first class contains methods regarding the paddle's position such as: moveUp and moveDown.
The main class that creates the game is the cGameManager which contains two objects from the cPaddle class(left and right paddle) and the ball object.


