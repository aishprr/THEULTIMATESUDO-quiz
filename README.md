theUltimateSudoqu_iz
====================

A Sudoku game that generates solvable Sudoku boards, and provides an interactive user interface that guides the user towards the solution, along with a timer and scores and varying levels based on user proficiency 

The Logic:

   In the code, we have supplied 4 different Sudoku puzzles of varying levels externally. Using a function that makes use of the ‘random’ command, one out of the 4 is selected once a player decides to start playing and clicks on ENTER GAME. The level is selected by the user, and this input is taken in. Using the logic that on exchanging any two rows or columns of a valid puzzle within one particular box, any different valid puzzle can be generated, each one of the 4 puzzles in our code is capable of producing 216 * 216 = 46656 different questions. One out of these 46656 is selected, again using a random function. This is stored in a 2D array and also copied into a file binary “qfile.dat” Once the level is specified by the user, as said before, one puzzle is displayed on the screen. 

   The user now starts playing and the timer starts ticking. For each entry to be made, the user clicks on the required box and enters the value. As soon as this happens, this validity of this entry according to the rules of the game is checked. Comparisons are made with the original question and the previous entries of the user. If it is invalid, a warning is flashed and the user will not be allowed to enter that value in that box. Also, any value previously entered can be changed at any point in the game. The user can decide to leave the game or play using a different question at which instant the solution of the present puzzle will be displayed. Once the user is done, his/her solution is checked by the program and an appropriate message is displayed.



How to Play this Game :

The opening page displays a button that allows the user to start playing the game. On clicking outside the displayed box, the user can directly exit the game without playing. When the user clicks on the button ENTER GAME, three difficulty levels appear and the user is allowed to choose his/her preferred level. 
The first level displays a question which provides 27 values to the user and the rest empty for the user to solve. Similarly, the second displays 26 values and the third 25. 
The user now has to try to solve the Sudoku. The timer displayed at the bottom of the screen allows the user to find out how much time he/she has taken to solve the Sudoku. At any stage, the player may decide to quit the game, or check his or her answer. If the user clicks on END GAME, the right solution will be displayed and the user will be given options to either leave the game completely or play the game again. If the user clicks on CHECK MY ANSWER, the user’s entries are compared with the correct solution and if it is right, the user is told so. If the final solution given by the user turns out to be wrong, again, the correct solution is displayed and the user is allowed to either play the game again or leave. If the user’s solution is right, an appropriate message is displayed, and then the user can decide to move onto a new question or exit the game.
