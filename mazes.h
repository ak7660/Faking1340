#ifndef MAZES_H
#define MAZES_H

#include <vector>
#include <string>

const std::vector<std::string> maze_template = {
    "+-+-------------+",
    "|O| |",
    "| +--- |",
    "| |",
    "+-- |",
    "| |",
    "+--------------E+"
};

const std::vector<std::string> maze1 = {
    "+-----+----+",
    "|O |",
    "| | | +-+ |",
    "| | | | |",
    "+-+ | +--+-+",
    "| | | |",
    "+---+--- |",
    "| | |",
    "| -------+-+",
    "| |",
    "+---------E+"
};

const std::vector<std::string> maze2 = {
    "+-+-+-----+-----+",
    "|O| | |",
    "| | | | --+ |",
    "| +-+ + | | | |",
    "| | +-+---+ |",
    "+-+---+ | |",
    "| | | | | | |",
    "| | ----+ | | | |",
    "| +-| | |",
    "| +-------+ | | |",
    "| | | |",
    "| +-+ -----+-+ |",
    "| | | |",
    "+---+---------+E+"
};

const std::vector<std::string> maze3 = {
    "+---------------+-------+",
    "|O | |",
    "+---+ +-------+ +-----+ |",
    "| | | | | | |",
    "| | | +---+ +-+-- --+ |",
    "| +-+---+---+ | | |",
    "| | | +-+ + |",
    "| ---------+ | | | | |",
    "| | | | | | |",
    "| +-------------+ | | +-+",
    "| +-+ | |",
    "+----+ +----------+ | |",
    "| | | | | |",
    "| ---+ +------------+ | |",
    "| | |",
    "+------+ +------+----+--+",
    "| | | |",
    "| +------+ +----| ----+ |",
    "| | |",
    "+---------------------+E+"
};

#endif // MAZES_H
