#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
#include <cstring>
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
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_row(can_be_edge ? 0 : 1, can_be_edge ? ROWS - 1 : ROWS - 2);
    uniform_int_distribution<> dis_col(can_be_edge ? 0 : 1, can_be_edge ? COLS - 1 : COLS - 2);

    return make_pair(dis_row(gen), dis_col(gen));
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
bool is_path_blocked(char map[ROWS][COLS], pair<int, int> player_pos, pair<int, int> destination_pos, pair<int, int> wall_pos)
{
    char temp_map[ROWS][COLS];
    memcpy(temp_map, map, sizeof(temp_map));

    temp_map[wall_pos.first][wall_pos.second] = '#';

    auto reachable_positions = get_reachable_positions(temp_map, player_pos);

    return find(reachable_positions.begin(), reachable_positions.end(), destination_pos) == reachable_positions.end();
}
int main()
{
    srand(time(nullptr));
    char map[ROWS][COLS];
    bool valid_map = false;

    while (!valid_map)
    {
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

        // Check if there's still a path from the player to the destination after placing the destination
        auto new_reachable_positions = get_reachable_positions(map, player_pos);
        if (find(new_reachable_positions.begin(), new_reachable_positions.end(),destination_pos) != new_reachable_positions.end())
        {
            valid_map = true;
        }

        // Arbitrary number of mini-game spots and teleport spots (between 7 and 13)
        // Arbitrary number of walls (between 27 and 40)
        int num_minigames = rand() % (13 - 7 + 1) + 7;
        int num_teleports = rand() % (13 - 7 + 1) + 7;
        int num_walls = rand() % (40 - 32 + 1) + 27;

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

        for (int i = 0; i < num_teleports; i++)
        {
            auto teleport_pos = random_position();
            while (!is_valid_position(teleport_pos, occupied_positions))
            {
                teleport_pos = random_position();
            }
            map[teleport_pos.first][teleport_pos.second] = '?';
            occupied_positions.push_back(teleport_pos);
        }

        for (int i = 0; i < num_walls; i++)
        {
            auto wall_pos = random_position();
            while (!is_valid_position(wall_pos, occupied_positions) || is_path_blocked(map, player_pos, destination_pos, wall_pos))
            {
                wall_pos = random_position();
            }
            map[wall_pos.first][wall_pos.second] = '#';
            occupied_positions.push_back(wall_pos);
        }
    }

    print_map(map);
    return 0;
}
