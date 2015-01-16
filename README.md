# SquareSwapper 5000

A Candy Crush inspired game for the final CS246 project.

### Building and Running the Program

Make sure you have the necessary library to compile graphics (**X11 recommended**).

Start and run an **X server**, export the display if necessary.

Compile the program by using the **make** command.

### Command Line Input

* **swap x y z** swaps the square at the **(x, y)** co-ordinate with the square in the **z** direction
	* 0 for north
	* 1 for south
	* 2 for west
	* 3 for east
* **hint** returns a valid move **(x, y, z)** as above that would lead to match
* **scramble** (available only if no moves are possible) reshuffles the squares on the board
* **levelup** increases the difficulty level of the game by one
* **leveldown** decreases the difficulty level of the game by one
* **restart** clears the board and starts a new game at the same level
* **End-of-file (EOF)** terminates the game

### Command Line Options

* **-text** runs the program in text-only mode, i.e. no graphics, default displays graphics
* **-seed x** sets the random number generator's seed to **x**
* **-scriptfile file** uses **file** for this level's intial board configuration
* **-startlevel n** starts the game in level **n**, default is level 0

###### Example
	./ss5k -text -startlevel 2
starts the game at level 2, in text only mode, and all other options as default

### Authors

<a href='https://github.com/fredcao'>@fredcao</a>
<p>
<a href='https://github.com/kevinchenxue'>@KevinChenXue</a>

