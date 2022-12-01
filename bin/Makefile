# Main program
main: 
	gcc ../src/adt/stackhistory/stackhistory.c ../src/adt/listdp/listdp.c ../src/adt/map/map.c ../src/adt/listscore/listscore.c ../src/adt/queue/queue.c ../src/adt/matrix/matrix.c ../src/adt/listlinier/listlinier.c ../src/adt/point/point.c ../src/adt/bintree/bintree.c ../src/adt/stack/stack.c ../src/adt/arraydin/arraydin.c ../src/adt/array/array.c ../src/adt/masakan/masakan.c ../src/adt/mesin/mesinkarakter.c ../src/adt/mesin/mesinkata.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/order/order.c ../src/games/dinerdash/dinerdash.c ../src/games/tictactoe/tictactoe.c ../src/games/towerofhanoi/towerofhanoi.c ../src/games/rng/rng.c ../src/games/snakeonmeteor/snakeonmeteor.c ../src/games/amogusfight/amogusfight.c ../src/games/hangman/hangman.c ../src/console.c ../src/main.c ../src/interface.c -o main

# Game
dinerdash:
	gcc ../src/games/dinerdash/mdinerdash.c ../src/adt/array/array.c ../src/games/dinerdash/dinerdash.c ../src/adt/order/order.c ../src/adt/masakan/masakan.c ../src/adt/string/string.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/interface.c -o dinerdash
rng:
	gcc ../src/games/rng/mrng.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/games/rng/rng.c -o rng
hangman:
	gcc ../src/games/hangman/mhangman.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/arraydin/arraydin.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/games/hangman/hangman.c ../src/interface.c -o hangman
tictactoe:
	gcc ../src/adt/matrix/matrix.c ../src/adt/mesin/mesinkarakter.c ../src/adt/string/string.c ../src/adt/mesin/mesinkata.c ../src/adt/word/word.c ../src/games/tictactoe/mtictactoe.c ../src/games/tictactoe/tictactoe.c -o tictactoe
towerofhanoi:
	gcc ../src/adt/mesin/mesinkarakter.c ../src/adt/string/string.c ../src/adt/stack/stack.c ../src/adt/mesin/mesinkata.c ../src/adt/word/word.c ../src/games/towerofhanoi/towerofhanoi.c ../src/games/towerofhanoi/mtowerofhanoi.c ../src/interface.c -o towerofhanoi
amogusfight:
	gcc ../src/adt/masakan/masakan.c ../src/adt/mesin/mesinkata.c ../src/adt/bintree/bintree.c ../src/adt/listlinier/listlinier.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/array/array.c ../src/games/amogusfight/amogusfight.c ../src/games/amogusfight/mamogusfight.c ../src/interface.c -o amogusfight
snakeonmeteor:
	gcc ../src/adt/listdp/listdp.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/point/point.c ../src/adt/mesin/mesinkarakter.c ../src/adt/mesin/mesinkata.c ../src/games/snakeonmeteor/snakeonmeteor.c ../src/games/snakeonmeteor/msnakeonmeteor.c ../src/interface.c -o snakeonmeteor

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
stackhistory:
	gcc ../src/adt/stackhistory/driverstackhistory.c ../src/adt/stackhistory/stackhistory.c ../src/adt/mesin/mesinkarakter.c ../src/adt/mesin/mesinkata.c ../src/adt/string/string.c ../src/adt/word/word.c -o stackhistory_test
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
	gcc ../src/adt/map/drivermap.c ../src/adt/map/map.c ../src/adt/word/word.c ../src/adt/string/string.c -o map_test
listscore:
	gcc ../src/adt/listscore/driverlistscore.c ../src/adt/listscore/listscore.c ../src/adt/map/map.c ../src/adt/mesin/mesinkata.c ../src/adt/mesin/mesinkarakter.c ../src/adt/word/word.c ../src/adt/string/string.c -o listscore_test