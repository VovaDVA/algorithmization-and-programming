using namespace std;

bool is_valid_position(vector<string> maze, int row, int col) {
    int rows = maze.size();
    int cols = maze[0].size();
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

bool is_can_exit_from_maze_helper(vector<string> maze, int row, int col, vector < vector < bool>> visited) {

    if (maze[row][col] == 'E') {
        return true;
    }

    visited[row][col] = true;

    vector < pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (const auto& dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        if (is_valid_position(maze, newRow, newCol) && !visited[newRow][newCol] && maze[newRow][newCol] != '#') {
            if (is_can_exit_from_maze_helper(maze, newRow, newCol, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool is_can_exit_from_maze(vector<string> maze, int row, int col) {
    int rows = maze.size();
    int cols = maze[0].size();

    if (!is_valid_position(maze, row, col)) {
        return false;
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    return is_can_exit_from_maze_helper(maze, row, col, visited);
}
