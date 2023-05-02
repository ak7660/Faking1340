def name():global player_name;print("\033[H\033[J", end="");print("-->Enter (Q) to exit<--");print("");temp = [i for i in players.keys()];temp = ', '.join(temp);print(f"Existing players: {temp}");print("");player_name = input("Enter an existing OR new player name to BEGIN: ");if player_name == "Q":return None;story();return 0
def generate(difficulty):global maze;maze = [];maze_temp = maze1 if difficulty == 1 else maze2 if difficulty == 2 else maze3;[maze.append([j for j in ''.join(maze_temp[i])]) for i in range(len(maze_temp))]
def distribute_items(difficulty):if difficulty == 1:num_stars = 8;num_tp = 5;elif difficulty == 2:num_stars = 15;num_tp = 10;elif difficulty == 3:num_stars = 25;num_tp = 20;num = 0;while num != num_stars:row = random.randrange(0, len(maze));column = random.randrange(0, len(''.join(maze[0])));if maze[row][column] == " ":maze[row][column] = "*";num += 1;num = 0;while num != num_tp:row = random.randrange(0, len(maze));column = random.randrange(0, len(''.join(maze[0])));if maze[row][column] == " ":maze[row][column] = "?";num += 1
def show():show = "";for i in range(len(maze)):for j in range(len(maze[i])):show += maze[i][j];show += " \n";print(show)
def get_position():for i in range(len(maze)):for j in range(len(maze[i])):if maze[i][j] == "O":return i, j
def possible_moves():moves = [];possibles = [" ", "?", "*", "E"];if maze[row-1][column] in possibles:moves.append("W");if maze[row+1][column] in possibles:moves.append("S");if maze[row][column-1] in possibles:moves.append("A");if maze[row][column+1] in possibles:moves.append("D");return moves
def move_O(direction):print("\033[H\033[J", end="");global quit;item = " ";if direction == "Q":quit = True;return None;maze[row][column] = " ";if direction == "W":item = maze[row-1][column];maze[row-1][column] = "O";elif direction == "S":item = maze[row+1][column];maze[row+1][column] = "O";elif direction == "A":item = maze[row][column-1];maze[row][column-1] = "O";elif direction == "D":item = maze[row][column+1];maze[row][column+1] = "O";if item == " ":return None;elif item == "E":return 0;elif item == "*":return 1;elif item == "?":return 2
def game():
    global step
    win = False
    print(f"{player_name}, now let's play a game..."); sleep(1)
    game = [0, 1, 2, 2, 2, 3, 3, 3]; game_name = ["tile", "sudoku", "TNTman", "Rock_Paper_Scissor"]
    choosen_game = random.choice(game)
    print("\033[H\033[J", end="")
    for i in range(5):
        for j in game_name:
            sleep(0.08); print(f"->Let's play {j}! ")
        print("\033[H\033[J", end="")
    print("\033[H\033[J", end=""); print(f"Let's play {game_name[choosen_game]}! ")
    if choosen_game == 0:
        win = tile.tile(difficulty)
    elif choosen_game == 1:
        win = sudoku.sudoku_main(str(difficulty))
    elif choosen_game == 2:
        win = tntman.hangman(difficulty)
    elif choosen_game == 3:
        win = rps.RPS()
    if win:
        print("\033[H\033[J", end=""); print(f"->{player_name} wins the game {game_name[choosen_game]}! Your steps taken will be decreased by 6! ")
        if step <= 6:
            step = 0
        else:
            step -= 6
        return
    else:
        print("\033[H\033[J", end=""); print(f"->{player_name} has lost or gave up in the game {game_name[choosen_game]}! You will be teleport back to where you started QvQ! ")
        row, column = get_position(); back_to_start(row, column)
        return

def teleport(original_row, original_column):
    while True:
        row = random.randrange(0, len(maze)); column = random.randrange(0, len(''.join(maze[0])))
        if maze[row][column] == " ":
            maze[original_row][original_column] = " "; maze[row][column] = "O"
            break
    print("->Random teleport, BAMF!!!")

def back_to_start(original_row, original_column):
    maze[original_row][original_column] = " "; maze[1][1] = "O"

def show_player_information():
    print(f"{player_name}'s steps taken --> {step}"); print("")

def read_file():
    global players
    decrypt(); file = open("ranking.txt")
    for line in file:
        players = json.loads(line)
    if type(players) != dict:
        players = {}

def update_file():
    global players
    with open('ranking.txt', 'w') as file:
        file.write(json.dumps(players))

def insert_player(player_name, step, difficulty):
    if difficulty == 1:
        weight = 3
    elif difficulty == 2:
        weight = 2
    elif difficulty == 3:
        weight = 1
    score = step * weight
    if (player_name in players.keys() and score < players[player_name]) or (player_name not in players.keys()):
        players[player_name] = score

def player_ranking():
    rank = []
    names = [i for i in players.keys()]
    steps = sorted(set([i for i in players.values()]))
    print(""); print("=======================RADIATION_LEVEL_RANKING=======================")
    count = 0
    for i in steps:
        count += 1
        temp = find_key_by_value(i)
        if len(temp) > 1:
            x = ""
            for name in range(len(temp)):
                if name == len(temp)-1:
                    x += f"{temp[name]}"
                else:
                    x += f"{temp[name]}, "
            print(" "*25, count, "->", x, ":", i)
        else:
            print(" "*25, count, "->", ''.join(temp), ":", i)

function find_key_by_value(i){let temp = [];for(let key, value in players.items()){if(i == value){temp.append(key)}}return temp}
let breaker = false, breaker2 = false;
try{read_file()}catch{fix.fix();fix.encrypt();read_file()}
while(true){while(true){difficulty = initiate();if(difficulty != null){name_Q = name()}if(difficulty == null || name_Q == null){breaker = true;break}generate(difficulty);distribute_items(difficulty);quit = false;step = 0;if(difficulty == 1){weight = 3}else if(difficulty == 2){weight = 2}else if(difficulty == 3){weight = 1}console.log("\033[H\033[J", end="");show();while(true){quit = false;event = null;row, column = get_position();moves = possible_moves();moves = ', '.join(moves);move = input(f"Enter a move ({moves}) OR (Q) back to Menu: ");console.log("");if(move.isalpha() && move in moves || move == "Q"){event = move_O(move);step += 1}else{console.log("\033[H\033[J", end="");console.log("->Invalid input")}if(quit){step -= 1;sure = input("->Press (Q) again to quit OR else return.(Your result will not be saved before you reach the exit!): ");if(sure == 'Q'){console.log("");console.log(f"{player_name} left the game!");sleep(1);breaker2 = true;break}}if(event == null){}else if(event == 0){console.log("\033[H\033[J", end="");show();console.log(f"Congratulations {player_name}! It took you {step} steps to reach the Exit! ");console.log("");console.log(f"Your corresponding RADIATION LEVEL = {step} X {weight} = {step*weight}");console.log("");console.log("This will be automatically updated on the ranking system if you are a new player OR your RADIATION LEVEL is lower than previous.");insert_player(player_name, step, difficulty);console.log("");x = input("Press ENTER to continue: ");break}else if(event == 1){game()}else if(event == 2){row, column = get_position();teleport(row, column)}show();show_player_information()}if(breaker2){break}if(breaker){break}}if(breaker){break}update_file();encrypt()}
