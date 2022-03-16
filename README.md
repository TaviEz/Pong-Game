# Pong-Game

**About**

Pong game made with C++ for the command line.

**Description**

The project is a console Pong Game written in C++ using classes, methods, for loops, while loops and also swtich statements. The paddles are made from the "\xDB" character and the borders from the "\xB2" character. I chose to structure the code into 3 main classes: cBall, cPaddle and cGameManager. The cBall class contains methods for its movement using the enumerator direction which dictates if the ball should go: left, upleft, downleft, right, upright,downright. The cPaddle class is used for creating the two paddles in the cGameManager class. The first class contains methods regarding the paddle's position such as: moveUp and moveDown. The main class that creates the game is the cGameManager which contains two objects from the cPaddle class(left and right paddle) and the ball object.

**Controls**

The controls for the left paddle are ```W``` and ```S``` and for the right paddle are ```O``` and ```L```. If you want different controls just change the 156-159 lines to your preference. If you want to close the game just press ```q```.

**Screenshots**

![pong](https://user-images.githubusercontent.com/100527261/158602699-d3205273-f3d7-4c0c-8ea5-0d879143ccc9.jpg)


**Issues to be fixed**

The paddles start moving after about a second if you hold one of the ```W S O L``` controls. On the other side, you can spam one of the control keys, but somtimes you will be late when trying to hit the ball.







