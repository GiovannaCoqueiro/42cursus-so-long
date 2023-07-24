<h1 align=center>
	<b>42cursus</b>
</h1>

<div align=center>
	<h2>
		<i>So Long</i>
	</h2>
	<img src="https://github.com/GiovannaCoqueiro/42cursus-so-long/assets/115947494/1b0cbee1-bdcd-41a1-be16-0fcf297a756e" alt=so long badge/>
	<p align=center>
    		Inside this repository, you can see all the code that has been created for the So Long project, including the mandatory part and the bonus part.
	</p>
</div>

---

<div align=center>
	<h2>
		Final score
	</h2>
	<img src= alt=so long grade/>
</div>

---

<h3 align=left>
  Death animation
</h3>
  <img src="https://github.com/GiovannaCoqueiro/42cursus-so-long/blob/main/gifs/death_animation.gif" alt=death animation/>

<h3 align=left>
  Victory animation
</h3>
  <img src="https://github.com/GiovannaCoqueiro/42cursus-so-long/blob/main/gifs/victory_animation.gif" alt=victory animation/>

---

<h3 align=left>
    Mandatory
</h3>
<p>
  Create a 2D game in which a character will escape a map after collecting everything it has to be collected.
</p>

<h4 align=left>
  Preparation
</h4>
<ul>
  <li>Use MinilibX.</li>
  <li>Turn in a Makefile to compile your program and it must not relink.</li>
  <li>The program must take as parameter a map file ending with the '.ber' extension.</li>
</ul>

<h4 align=left>
  Game
</h4>
<ul>
  <li>The player must collect every collectible present on the map and then escape through the exit.</li>
  <li>The player must be moved by pressing AWSD keys or the arroy keys.</li>
  <li>The player must be moved in 4 directions: left, right, down and up.</li>
  <li>The player can't move into a wall.</li>
  <li>The program must display the movement count in the terminal.</li>
  <li>The game must be a 2D view.</li>
</ul>

<h4 align=left>
  Graphic management
</h4>
<ul>
  <li>The program must display the image in  awindow.</li>
  <li>The window must close and the program must quit when the user press ESC or click on the cross on the window.</li>
</ul>

<h4 align=left>
  Map
</h4>
<ul>
  <li>The map must be composed for five elements (6 if you implement the bonus part).</li>

  | Char | Element |
  | :---: | :---: |
  | 0 | ground |
  | 1 | wall |
  | C | collectible |
  | E | exit |
  | P | player starting position |

  <li>The map must contain exactly 1 exit, 1 player starting position and at least 1 collectible.</li>
  <li>The map must be rectangular.</li>
  <li>The map must be surrounded by walls.</li>
  <li>The map must have a valid path between the player starting position and the exit, and be able to collect all the collectibles.</li>
</ul>

---

<h3 align=left>
    Bonus
</h3>
<ul>
  <li>Add some enemy and make the player lose qhen they touch it.</li>
	
  | Char | Element |
  | :---: | :---: |
  | X | enemy |
  
  <li>Add animation.</li>
  <li>Diaplay the steps count on the screen.</li>
</ul>

---

<h2>
    Instructions to use
</h2>
Clone this repository in you local computer using a terminal:
<ul>
	<li>$> git clone git@github.com:GiovannaCoqueiro/42cursus-so-long.git [repository_local]</li>
</ul>
		
After cloning the project in your local reposiory you can run some commands you can find in Makefile:
<ul>
	<li>$> <b>make all:</b> or just <b>make</b> compiles the project</li>
	<li>$> <b>make bonus:</b> compiles the project</li>
	<li>$> <b>make clean:</b> deletes the object files created during compilation</li>
	<li>$> <b>make fclean:</b> executes the <b>clean</b> command and also deletes the libftprintf.a</li>
	<li>$> <b>make re:</b> executes the <b>fclean</b> command followed by the <b>all</b> command</li>
</ul>

Than you can run the game with: ./so_long maps/<map_file.ber>
You can also create and run any map, if it follows the requirements.
