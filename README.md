<h1 align="center">
	Cub3D
</h1>

<div align="center">
	<blockquote>
  	"This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever."
	<br>
  	"Now, it’s your turn to relive History..."
	</blockquote>
</div>

---

<h2 align="center">
	Description
</h2>

The aim of this project is to explore ray-casting with the goal to make a dynamic view inside a maze.

It is the second design project in the 42Cursus and the students are able to learn about graphics, events and masks, colors, fill shapes, windows, etc.

To be able to do this 3D Game is necessary to "explore the playful practical applications of mathematics without having to understand the specifics.

The project must be done using the Ray-Casting principles and it should be a 3D graphical representation from inside of a maze from a first-person perpective.

<img src="https://user-images.githubusercontent.com/76601093/196152674-c0c44b7b-e214-4340-954a-e763b8fc1d92.png" align="center">

(image from ```scawy.cub``` (horror themed map), different maps have different themes)

---

<h2 align="center">
	How to install minilbx
</h2>

    git clone https://github.com/42Paris/minilibx-linux.git
    cd minilibx-linux

    sudo apt install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev

    make
    
	cd /usr/local/man/
	sudo mkdir man1

    (Return to the minilibx-linux directory)

    sudo cp man/man1/* /usr/local/man/man1/
    sudo cp libmlx.a /usr/local/lib/
    sudo cp mlx.h /usr/local/include/
    
    man mlx
    (Must show the minilibx manual)

---

<h2 align="center">
	How to run:
</h2>

- ```make```
- ```./cub3D maps/scawy.cub``` (instead of ```scawy.cub``` you can choose any other map in the ```maps``` folder)

IMPORTANT: This game was made for Mac, you can open the game but may not be able to move on linux because of the key bindings.

---

<h2 align="center">
	Documentation
</h2>

<!---
<div align="center">
	<a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html">42 Docs - MiniLibX</a> | <a href="https://lodev.org/cgtutor/raycasting.html">Raycasting - Lode Vandevenne </a>
</div>
--->

- [42 Docs - MinilibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [Raycasting - Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html)

---

<div align="center">
	<img src="https://user-images.githubusercontent.com/76601093/193692098-d4b16956-1dab-40b8-9aae-31b254efc5ee.jpg" width=340> <img src="https://user-images.githubusercontent.com/76601093/196162497-50fa62e6-041b-414c-b51b-1008ad06eab9.png">

</div>
