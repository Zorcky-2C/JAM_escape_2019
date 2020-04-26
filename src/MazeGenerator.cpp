#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

std::vector<std::vector<int>> arr = {};
std::vector<std::vector<int>> arr2 = {};
std::vector<std::vector<int>> neigh = {};
int r = 1; //row
int c = 1; //column
std::vector<int> nxt = {};
int count = 1;

// ====== MAZE GENERATOR FUNC ========
int generate_maze(int h, int w)
{
  neigh.clear();
  //== counter to end recursive call quickly
  if (count >= (h / 2) * (w / 2))
    return 0;
  //==== getting the unvisited neighbors
  if (r + 2 < h - 1 && arr[r + 2][c] == 0)
    neigh.push_back({r + 2, c}); //down
  if (r - 2 > 0 && arr[r - 2][c] == 0)
    neigh.push_back({r - 2, c}); //up
  if (c + 2 < w - 1 && arr[r][c + 2] == 0)
    neigh.push_back({r, c + 2}); //right
  if (c - 2 > 0 && arr[r][c - 2] == 0)
    neigh.push_back({r, c - 2}); //left
  //=== forward
  if (neigh.size() > 0) {
    nxt.clear();
    nxt = neigh[rand() % neigh.size()];
    //mark it as visited
    arr[nxt[0]][nxt[1]] = 2;
    //counter to know if all cells are already visited
    count++;
    //push to the stack
    arr2.push_back(nxt);
    //remove the walls
    if (c - nxt[1] < 0) {
      arr[r][c + 1] = 0;
      c += 2;
      generate_maze(h, w);
    } else if (c - nxt[1] > 0) {
      arr[r][c - 1] = 0;
      c -= 2;
      generate_maze(h, w);
    } else if (r - nxt[0] < 0) {
      arr[r + 1][c] = 0;
      r += 2;
      generate_maze(h, w);
    } else if (r - nxt[0] > 0) {
      arr[r - 1][c] = 0;
      r -= 2;
      generate_maze(h, w);
    }
  }
  //==== backtrack
  else if (arr2.size() > 0) {
    arr2.pop_back();
    r = arr2[arr2.size() - 1][0];
    c = arr2[arr2.size() - 1][1];
    generate_maze(h, w);
  }
  return 0;
}

std::string create_maze(int h, int w)
{
  std::string maze;
  //adjusting the size
  if (h % 2 == 0)
    h++;
  if (w % 2 == 0)
    w++;
  // getting time as seed
  time_t seed;
  seed = time(0);
  srand(seed % 1000);

  //===== creating the base of the maze
  arr.resize(h);
  for (int j = 0; j < h; j++) {
    arr[j].resize(w);
    for (int i = 0; i < w; i++) {
      if (j % 2 == 1 && i % 2 == 1)
        arr[j][i] = 0;
      else if ((j == 0 && i == 1) || (j == h - 1 && i == w - 2))
        arr[j][i] = 0;
      else
        arr[j][i] = 1;
    }
  }

  //==== starting point of maze creation using depth-first search and recursive backtracking
  arr[r][c] = 2;
  arr2.push_back({r, c});

  //=== generate maze
  generate_maze(h, w);

  //===== put maze in file
  for (int j = 0; j < h; j++) {
    for (int i = 0; i < w; i++) {
      if (arr[j][i] == 1)
        maze.append("X");
      else if (j == 0 && i == 1)
        maze.append("S");
      else if (j == h - 1 && i == w - 2)
        maze.append("E");
      else {
        if (arr[j][i] == 2)
          arr[j][i] = 0;
        maze.append(" ");
      }
    }
    maze.append("\n");
  }
  maze.pop_back();
  return maze;
}