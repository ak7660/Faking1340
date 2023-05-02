from time import sleep
import sys
import random
import json
from cryptography.fernet import Fernet
import fix
import sudoku
import tile
import tntman
import rps
maze_template = [["+-+-------------+"],["|O|             |"],["| +---          |"],["|               |"],["+--             |"],["|               |"],["+--------------E+"]]
maze1 = [["+-----+----+"],["|O         |"],["| | | +-+  |"],["| | | |    |"],["+-+ | +--+-+"],["|   |    | |"],["+---+---   |"],["|        | |"],["| -------+-+"],["|          |"],["+---------E+"]]
maze2 = [["+-+-+-----+-----+"],["|O|       |     |"],["| | |     | --+ |"],["| +-+ + | |   | |"],["|     | +-+---+ |"],["+-+---+ |       |"],["| |     | | | | |"],["| | ----+ | | | |"],["|         +-| | |"],["| +-------+ | | |"],["|           | | |"],["| +-+  -----+-+ |"],["|   |         | |"],["+---+---------+E+"]]
maze3 = [["+---------------+-------+"],["|O              |       |"],["+---+ +-------+ +-----+ |"],["|   | |       | |     | |"],["| | |   +---+ +-+-- --+ |"],["| +-+---+---+ |       | |"],["| |           | +-+ +   |"],["|    ---------+ | | | | |"],["| |             | | | | |"],["| +-------------+ | | +-+"],["|                 +-+ | |"],["+----+ +----------+   | |"],["|    | |            | | |"],["| ---+ +------------+ | |"],["|      |                |"],["+------+ +------+----+--+"],["|        |      |       |"],["| +------+ +----| ----+ |"],["|                     | |"],["+---------------------+E+"]]
def initiate():
    logo = [  "  ________ __                    __    ___________                   ",                 
              " /  _____/|  |__   ____  _______/  |_  \__    ___/_____  _  ______   ", 
              "/   \  ___|  |  \ /  _ \/  ___/\   __\   |    | /  _ \ \/ \/ /    \  ",
              "\    \_\  \   Y  (  <_> )___ \ |  |      |    |(  <_> )     /   |  \ ",
              "\______  /___|  /\____/____  > |__|      |____| \____/ \/\_/|___|  / ",
              "       \/     \/           \/                                    \/  "]
    invalid = False
    while True:
        print("\033[H\033[J", end="")
        if invalid:
            print("->Invalid input, try again! ")
        print("=====================================================================")
        for i in logo:
                print(i)
        player_ranking()
        print("=====================================================================")
        print("")
        print("-->Enter (Q) to exit<--")
        print("")
        while True:
            user_input = input("Enter difficulty (1~3): ")
            if user_input.isdigit() and 0 < int(user_input) < 4 :
                    return int(user_input)
            elif user_input == "Q":
                return None
            else:
                invalid = True
                break
def story():
    print("\033[H\033[J", end="")
    x = input("Press ENTER to read the story & rules OR (E) start the game directly: ")
    print("\033[H\033[J", end="")
    text = ["Background story: ",
            "",
            "->In 1986, a nuclear leak accident occured nearby your hometown.",
            "->Millions of innocent villagers were exposed to highly radioactive chemicals.",
            "->You need to escape this Ghost Town as soon as possible!"]
    image = [
           "+-----------+/__\  _      / \      /   /     ( )| | |                     |   ( )_)| | (_)_)    ",
           "|_|_|_|_|_|_||__| / \    /___\    /   /    (__)_) | | NUCLEAR POWER PLANT |  (__)_)| | | |     ",
           "|_|_|_|_|_|_|    /   \   |   |   /   /     |  | |_| |                     |   |  | |_| | |    ",
           "|_|_|_|_|_|_|   /_____\  |___|  /   /      |  |     |                     |   |  |     | |     ",
           "|_|_|_|_|_|_|   |     |        /   /       |  |     |       _______       |   |  |     | |     ",
           "|   |   |   |   |  _  |       /   /        |  |     |      |       |      |   |  |     |_|     ",
           "|___________|   |_|_|_|      /   /         |__|     |______|_______|______|   |__|                  ",
        ]
    if x != "E":
        for i in image:
            print(i)
        print("============================================================================================")
        for i in text:
            for j in i:
                print(j, end = "")
                sys.stdout.flush()
                sleep(0.04)
            print('')
        print("")
        a = input("Press ENTER to continue: ")
        print("\033[H\033[J", end="")
        print("Rules: ")
        print("")
        print("->Enter (W, A, S, D) to move and find a way to the exit (E) in the maze, each move will be recorded as one step.")
        print("->Items in the maze: (*) = Randomly played a game (difficulty of the game depends on the difficulty chose at the beginning).")
        print("                           If you win your steps will be decreased by 6.")
        print("                           If you gave up or lost you will be teleported back to where you started.")
        print("                     (?) = Random teleport.")
        print("->Depending on the choosen difficulty level, the final score (RADIATION LEVEL) = steps X weight")
        print("->Difficulty 1: weight = 3, Difficulty 2: weight = 2, Difficulty 3: weight = 1.")
        print("->The lower the RADIATION LEVEL, the higher the rank.")
        print("->The score will only be updated on the ranking system after you reach the exit and if you are a new player OR your RADIATION LEVEL is lower than previous.")
        print("->The goal is to escape the Ghost Town with minimum steps! ")
        print("")
        x = input("Press ENTER to continue: ")
def name():
    global player_name
    print("\033[H\033[J", end="")
    print("-->Enter (Q) to exit<--")
    print("")
    #Print existing players
    temp = [i for i in players.keys()]
    temp = ', '.join(temp)
    print(f"Existing players: {temp}")
    print("")
    player_name = input("Enter an existing OR new player name to BEGIN: ")
    if player_name == "Q":
        return None
    story()
    return 0
def generate(difficulty):
        global maze
        maze = []
        if difficulty == 1:
                maze_temp = maze1
        elif difficulty == 2:
                maze_temp = maze2
        elif difficulty == 3:
                maze_temp = maze3
        for i in range(len(maze_temp)):
                temp = []
                line = "".join(maze_temp[i])
                for j in line:
                        temp.append(j)
                maze.append(temp)
def distribute_items(difficulty):
        if difficulty == 1:
                num_stars = 8
                num_tp = 5
        elif difficulty == 2:
                num_stars = 15
                num_tp = 10
        elif difficulty == 3:
                num_stars = 25
                num_tp = 20
        #Randomly assigned * and ?
        num = 0
        while num != num_stars:
                row = random.randrange(0, len(maze))
                column = random.randrange(0, len(''.join(maze[0])))
                if maze[row][column] == " ":
                        maze[row][column] = "*"
                        num += 1
        num = 0
        while num != num_tp:
                row = random.randrange(0, len(maze))
                column = random.randrange(0, len(''.join(maze[0])))
                if maze[row][column] == " ":
                        maze[row][column] = "?"
                        num += 1
def show():
        show = ""
        for i in range(len(maze)):
                for j in range(len(maze[i])):
                        show += maze[i][j]
                show += " \n"
        print(show)
def get_position():
        for i in range(len(maze)):
                for j in range(len(maze[i])):
                        if maze[i][j] == "O":
                                return i, j
def possible_moves():
        moves = []
        possibles = [" ", "?", "*", "E"]
        if maze[row-1][column] in possibles:
                moves.append("W")
        if maze[row+1][column] in possibles:
                moves.append("S")
        if maze[row][column-1] in possibles:
                moves.append("A")
        if maze[row][column+1] in possibles:
                moves.append("D")
        return moves
def move_O(direction):
        print("\033[H\033[J", end="")
        global quit
        item = " "
        if direction == "Q":
                quit = True
                return None
        maze[row][column] = " "
        if direction == "W":
                item = maze[row-1][column]   
                maze[row-1][column] = "O"
        elif direction == "S":
                item = maze[row+1][column]
                maze[row+1][column] = "O"
        elif direction == "A":
                item = maze[row][column-1]
                maze[row][column-1] = "O"
        elif direction == "D":
                item = maze[row][column+1]
                maze[row][column+1] = "O"
        #Check for item [" ", *, ?, E]
        if item == " ":
                return None #None
        elif item == "E":
                return 0 #Win
        elif item == "*":
                return 1 #Game
        elif item == "?":
                return 2 #Transport
def game():
        global step
        win = False
        print(f"{player_name}, now let's play a game...")
        sleep(1)
        game = [0, 1, 2, 2, 2, 3, 3, 3 ] # 0: tile 1: sudoku 2: tntman 3: Rock Paper Scissor
        game_name = ["tile", "sudoku", "TNTman", "Rock_Paper_Scissor"]
        choosen_game = random.choice(game)
        print("\033[H\033[J", end="")
        for i in range(5):
                for j in game_name:
                        sleep(0.08)
                        print(f"->Let's play {j}! ")
                        print("\033[H\033[J", end="")
        print("\033[H\033[J", end="")
        print(f"Let's play {game_name[choosen_game]}! ")
        if choosen_game == 0:
                win = tile.tile(difficulty)
        elif choosen_game == 1:
                win = sudoku.sudoku_main(str(difficulty))
        elif choosen_game == 2:
                win = tntman.hangman(difficulty)
        elif choosen_game == 3:
            win = rps.RPS()
        #Win/lost
        if win:
                print("\033[H\033[J", end="")
                print(f"->{player_name} wins the game {game_name[choosen_game]}! Your steps taken will be decreased by 6! ")
                if step <= 6:
                        step = 0
                else:
                        step -= 6
                return
        else:
                print("\033[H\033[J", end="")
                print(f"->{player_name} has lost or gave up in the game {game_name[choosen_game]}! You will be teleport back to where you started QvQ! ")
                row, column = get_position()
                back_to_start(row, column)
                return
def teleport(original_row, original_column):
        while True:
                row = random.randrange(0, len(maze))
                column = random.randrange(0, len(''.join(maze[0])))
                if maze[row][column] == " ":
                        maze[original_row][original_column] = " "
                        maze[row][column] = "O"
                        break
        print("->Random teleport, BAMF!!!")
def back_to_start(original_row, original_column):
        maze[original_row][original_column] = " "
        maze[1][1] = "O"
def show_player_information():
        print(f"{player_name}'s steps taken --> {step}")
        print("")
def read_file():
    global players
    decrypt()
    file = open("ranking.txt")
    for line in file:
        players = json.loads(line)
    #In case if players is not dict
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

#Algorithm ranking players using dictionary
def player_ranking():
        rank = []
        names = [i for i in players.keys()]
        steps = sorted(set([i for i in players.values()]))
        print("")
        print("=======================RADIATION_LEVEL_RANKING=======================")
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
def find_key_by_value(i):
        temp = []
        for key, value in players.items():
                if i == value:
                        temp.append(key)
        return temp
breaker = False
breaker2 = False
try:
        read_file()
except:
        fix.fix()
        fix.encrypt()
        read_file()                     
while True:
    while True:
        print("\033[H\033[J", end="") #Clear the console
        difficulty = initiate()
        #Quit the game
        if difficulty != None:
            name_Q = name()
        if difficulty == None or name_Q == None:
            print("\033[H\033[J", end="")
            print("->BYE BYE~")
            breaker = True
            break
        generate(difficulty) #Choose a difficulty from 1 to 3. 1: Easy maze, minimum
        distribute_items(difficulty) #Randomly distribute items in the maze
        quit = False
        step = 0
        if difficulty == 1:
            weight = 3
        elif difficulty == 2:
            weight = 2
        elif difficulty == 3:
            weight = 1
        print("\033[H\033[J", end="")
        show()
        while True:
                quit = False
                event = None
                row, column = get_position() #Get current position
                moves = possible_moves() #Get possible moves
                moves = ', '.join(moves)
                move = input(f"Enter a move ({moves}) OR (Q) back to Menu: ")
                print("")
                #Check if it is valid
                if move.isalpha() and move in moves or move == "Q":
                        event = move_O(move)
                        step += 1
                else:
                        print("\033[H\033[J", end="")
                        print("->Invalid input")
                if quit:
                        step -= 1
                        sure = input("->Press (Q) again to quit OR else return.(Your result will not be saved before you reach the exit!): ")
                        if sure == 'Q':
                            print("")
                            print(f"{player_name} left the game!")
                            sleep(1)
                            breaker2 = True
                            break
                if event == None:
                        pass
                elif event == 0:  #events--> 0 = win, 1 = Game, 2 = Transport
                        print("\033[H\033[J", end="")
                        show()
                        print(f"Congratulations {player_name}! It took you {step} steps to reach the Exit! ")
                        print("")
                        print(f"Your corresponding RADIATION LEVEL = {step} X {weight} = {step*weight}")
                        print("")
                        print("This will be automatically updated on the ranking system if you are a new player OR your RADIATION LEVEL is lower than previous.")
                        insert_player(player_name, step, difficulty)
                        print("")
                        x = input("Press ENTER to continue: ")
                        break
                elif event == 1:
                        game()
                elif event == 2:
                        row, column = get_position()
                        teleport(row, column)
                
                show()
                show_player_information()
        if breaker2:
            break
        if breaker:
            break
    if breaker:
        break
update_file()
encrypt()
