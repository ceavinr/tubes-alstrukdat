# Main program
main: 
	gcc ../src/adt/map/map.c ../src/adt/set/set.c ../src/adt/scoreboard/scoreboard.c ../src/adt/queue/queue.c ../src/adt/matrix/matrix.c ../src/adt/bintree/bintree.c ../src/adt/stack/stack.c ../src/adt/arraydin/arraydin.c ../src/adt/array/array.c ../src/adt/masakan/masakan.c ../src/adt/mesin/mesinkarakter.c ../src/adt/mesin/mesinkata.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/order/order.c ../src/games/dinerdash/dinerdash.c ../src/games/tictactoe/tictactoe.c ../src/games/towerofhanoi/towerofhanoi.c ../src/games/rng/rng.c ../src/console.c ../src/main.c ../src/gambar.c -o main

# Game
dinerdash:
	gcc ../src/games/dinerdash/mdinerdash.c ../src/adt/array/array.c ../src/games/dinerdash/dinerdash.c ../src/adt/order/order.c ../src/adt/masakan/masakan.c ../src/adt/string/string.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/gambar.c -o dinerdash
rng:
	gcc ../src/games/rng/mrng.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/games/rng/rng.c -o rng
tictactoe:
	gcc ../src/adt/matrix/matrix.c ../src/adt/mesin/mesinkarakter.c ../src/adt/string/string.c ../src/adt/mesin/mesinkata.c ../src/adt/word/word.c ../src/games/tictactoe/mtictactoe.c ../src/games/tictactoe/tictactoe.c -o tictactoe
towerofhanoi:
	gcc ../src/adt/mesin/mesinkarakter.c ../src/adt/string/string.c ../src/adt/stack/stack.c ../src/adt/mesin/mesinkata.c ../src/adt/word/word.c ../src/games/towerofhanoi/towerofhanoi.c ../src/games/towerofhanoi/mtowerofhanoi.c -o towerofhanoi
amogusfight:
	gcc ../src/adt/masakan/masakan.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/array/array.c ../src/games/amogusfight/amogusfight.c ../src/games/amogusfight/mamogusfight.c -o amogusfight

# Mesin kata & Mesin karakter
mesin:
	gcc ../src/adt/mesin/drivermesin.c ../src/adt/mesin/mesinkata.c ../src/adt/string/string.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c -o mesin_test

# ADT test
word:
	gcc ../src/adt/word/driverword.c ../src/adt/mesin/mesinkata.c ../src/adt/string/string.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c -o word_test
string:
	gcc ../src/adt/string/driverstring.c ../src/adt/string/string.c -o string_test
order:
	gcc ../src/adt/order/driverorder.c ../src/adt/order/order.c ../src/adt/masakan/masakan.c -o order_test
stack:
	gcc ../src/adt/stack/driverstack.c ../src/adt/stack/stack.c -o stack_test
bintree:
	gcc ../src/adt/bintree/driverbintree.c ../src/adt/arraydin/arraydin.c ../src/adt/bintree/bintree.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c -o bintree_test
array:
	gcc ../src/adt/array/driverarray.c ../src/adt/array/array.c ../src/adt/masakan/masakan.c -o array_test
matrix:
	gcc ../src/adt/matrix/drivermatrix.c ../src/adt/matrix/matrix.c -o matrix_test
masakan:
	gcc ../src/adt/masakan/drivermasakan.c ../src/adt/masakan/masakan.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c -o masakan_test
arraydin:
	gcc ../src/adt/arraydin/driverarraydin.c ../src/adt/arraydin/arraydin.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/string/string.c ../src/adt/word/word.c -o arraydin_test
queue:
	gcc ../src/adt/queue/driverqueue.c ../src/adt/queue/queue.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/string/string.c ../src/adt/word/word.c -o queue_test
map:
	gcc ../src/adt/map/drivermap.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/map/map.c -o map_test
set:
	gcc ../src/adt/set/driverset.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/set/set.c -o set_test
scoreboard:
	gcc ../src/adt/scoreboard/driverscoreboard.c ../src/adt/scoreboard/scoreboard.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/map/map.c ../src/adt/set/set.c -o scoreboard_test