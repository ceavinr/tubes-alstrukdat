# KELOMPOK 13INOMCUK

### Pre-requisite

- MinGW

## How to Use (Windows):

1.  Main Program (Alternatif 1)

    ```
    mingw32-make -C bin main
    ./bin/main
    ```

2.  Main Program (Alternatif 2)

    ```
    gcc ../src/adt/queue/queue.c ../src/adt/stack/stack.c ../src/adt/arraydin/arraydin.c ../src/adt/array/array.c ../src/adt/mesinkarakter/mesinkarakter.c ../src/adt/mesinkata/mesinkata.c ../src/adt/word/word.c ../src/adt/string/string.c ../src/adt/order/order.c ../src/games/dinerdash/dinerdash.c ../src/games/tictactoe/tictactoe.c ../src/games/towerofhanoi/towerofhanoi.c ../src/games/rng/rng.c ../src/console.c ../src/main.c ../src/gambar.c -o main
    ```

    kemudian run main.exe dengan cara membuka file .exe (bukan menjalankan melalui terminal)

3.  RNG

    ```
    mingw32-make -C bin rng
    ./bin/rng
    ```

4.  Diner Dash

    ```
    mingw32-make -C bin dinerdash
    ./bin/dinerdash
    ```

5.  Tower of Hanoi

    ```
    mingw32-make -C bin towerofhanoi
    ./bin/towerofhanoi
    ```
