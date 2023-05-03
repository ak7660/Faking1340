#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int ROWS = 11;
const int COLS = 19;

void print_map(char map[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

pair<int, int> random_position(bool can_be_edge = false)
{
    if (can_be_edge)
    {
        return make_pair(rand() % ROWS, rand() % COLS);
    }
    else
    {
        return make_pair(rand() % (ROWS - 2) + 1, rand() % (COLS - 2) + 1);
    }
}

bool is_valid_position(pair<int, int> pos, vector<pair<int, int>> &occupied_positions)
{
    return find(occupied_positions.begin(), occupied_positions.end(), pos) == occupied_positions.end();
}

vector<pair<int, int>> get_reachable_positions(char map[ROWS][COLS], pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);

    vector<pair<int, int>> visited;
    visited.push_back(start);

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        for (const auto &dir : directions)
        {
            int new_row = current.first + dir.first;
            int new_col = current.second + dir.second;

            if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS)
            {
                pair<int, int> new_pos = make_pair(new_row, new_col);
                if (is_valid_position(new_pos, visited) && map[new_row][new_col] != '#')
                {
                    visited.push_back(new_pos);
                    q.push(new_pos);
                }
            }
        }
    }

    return visited;
}

int main()
{
    srand(time(nullptr));
    char map[ROWS][COLS];

    // Initialize map with walls and empty spaces
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
            {
                map[i][j] = '#';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }

    vector<pair<int, int>> occupied_positions;

    // Place player 'O'
    auto player_pos = make_pair(1, 1);
    map[player_pos.first][player_pos.second] = 'O';
    occupied_positions.push_back(player_pos);

    // Get reachable positions from the starting position
    auto reachable_positions = get_reachable_positions(map, player_pos);

    // Place destination 'E'
    auto destination_pos = reachable_positions[rand() % reachable_positions.size()];
    map[destination_pos.first][destination_pos.second] = 'E';
    occupied_positions.push_back(destination_pos);

    // Remove occupied positions from reachable_positions
    reachable_positions.erase(remove(reachable_positions.begin(), reachable_positions.end(), destination_pos), reachable_positions.end());

    // Place mini-game spots '*' with random occurrences between 7 and 13
    int num_minigames = rand() % (13 - 7 + 1) + 7;
    for (int i = 0; i < num_minigames; i++)
    {
        auto minigame_pos = random_position();
        while (!is_valid_position(minigame_pos, occupied_positions))
        {
            minigame_pos = random_position();
        }
        map[minigame_pos.first][minigame_pos.second] = '*';
        occupied_positions.push_back(minigame_pos);
    }

    // Place random teleport spots '?' with random occurrences between 7 and 13
    int num_teleports = rand() % (13 - 7 + 1) + 7;
    for (int i = 0; i < num_teleports; i++)
    {
        auto teleport_pos = reachable_positions[rand() % reachable_positions.size()];
        while (!is_valid_position(teleport_pos, occupied_positions))
        {
            teleport_pos = reachable_positions[rand() % reachable_positions.size()];
        }
        map[teleport_pos.first][teleport_pos.second] = '?';
        occupied_positions.push_back(teleport_pos);
        reachable_positions.erase(remove(reachable_positions.begin(), reachable_positions.end(), teleport_pos), reachable_positions.end());
    }

    // Place random walls '#' inside the map
    int num_walls = rand() % (40 - 32 + 1) + 27;
    for (int i = 0; i < num_walls; i++)
    {
        auto wall_pos = random_position();
        while (!is_valid_position(wall_pos, occupied_positions))
        {
            wall_pos = random_position();
        }
        map[wall_pos.first][wall_pos.second] = '#';
        occupied_positions.push_back(wall_pos);
    }
    // Create a new vector called valid_transfer_positions with the remaining reachable_positions
    vector<pair<int, int>> valid_transfer_positions = reachable_positions;

    // Print the map
    print_map(map);

    // Output valid_transfer_positions to standard error
    cerr << "Valid Transfer Positions:" << endl;
    for (const auto &pos : valid_transfer_positions)
    {
        cerr << "(" << pos.first << ", " << pos.second << ")" << endl;
    }

    return 0;

    return 0;
}
