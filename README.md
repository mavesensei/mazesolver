# Random Maze Generator and Path Finder Algorithm
This code implements a random maze generator and a pathfinding algorithm. It creates a maze, marks paths, and finds a route from the entrance to the exit.<br><br><br>
**Phase 1: (Walls and paths creation)**
The maze starts with all walls. The entrance and exit are critical; the maze generation begins from the entrance and aims to create a path to the exit.
In this example, a 25x25 maze is generated. The entrance is placed randomly along the left wall, while the exit is placed randomly on the right wall.
Only one valid path is created between the entrance and exit, with all other routes leading to dead ends.<br><br><br>
**Phase 2: (Pathfinding and Visited Locations)**
The algorithm uses a recursive depth-first search to explore the maze. Cells along the path are marked as VISITED to track progress.
When the algorithm reaches a crossroads, it checks available paths. If a direction leads to a dead end, it backtracks and explores other options.<br><br><br>
**Phase 3: (Final path)**
Once the exit is reached, the path from the entrance to the exit is marked with the FINAL state. This allows the final path to be visually distinguished from other paths.<br><br><br>
**(Potential Bugs) Entrance/Exit Placement: **
There is a risk that the entrance or exit may be placed next to an enclosed area of walls, leading to scenarios where the pathfinding fails to find a route. This results in the message "No path found!"<br>
<br>
**WALL's are shown as (#)**<br>
**PATH's are shown as ( )**<br>
**FINAL PATH is shown as (.)**<br>
