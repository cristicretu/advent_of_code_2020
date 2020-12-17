from pprint import pprint

lines = list()

with open("/home/cristic/Projects/aoc2020/input.in", "r") as f:
    lines = [line.strip() for line in f.readlines()]

pprint(lines)

width = len(lines[0])
height = len(lines)

routes = [(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)]


def get_next_spot(x, y, route):
    y = y + route[1]
    x = x + route[0]
    if x > width:
        x = x % width
    return x, y


x = 1
y = 1

all_trees = 1

for route in routes:
    trees = 0
    y = route[1]
    x = 1
    j = 0
    lines_new = list(lines)
    for line in lines[1:]:
        s = line
        if (j + 1) % (route[1]) == 0:
            x, y = get_next_spot(x, y, route)
            s = line[:x - 1] + "O" + line[x:]
            if line[x - 1] == "#":
                trees += 1
                s = line[:x - 1] + "X" + line[x:]
        lines_new[j + 1] = s
        j = j + 1
    all_trees = all_trees * trees

print(all_trees)
