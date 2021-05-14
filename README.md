# ASCII-based tic-tac-toe game  
A simple tic-tac-toe game  

usage in unix systems:

```
$ make all #clears older version, compiles and runs the program.
```

If you want to run this on windows, you can simply change the compiler from the makefile.  
Also please change this place in the code too if you use in windows:  

```
8 #define clear "clear" /* you can change this to "cls" for windows */
```

some examples:  

```

                                |                        |
                                |                        |
              ZZ      ZZ        |          ZZZZ          |
                ZZ   ZZ         |        ZZ    ZZ        |
                 ZZ ZZ          |       ZZ      ZZ       |
                  ZZZ           |       ZZ      ZZ       |
                 ZZ ZZ          |       ZZ      ZZ       |
                ZZ   ZZ         |        ZZ    ZZ        |
              ZZ      ZZ        |          ZZZZ          |
                                |                        |
        ------------------------|------------------------|--------------------------
        ------------------------|------------------------|--------------------------
                                |                        |
                                |                        |
                                |          ZZZZ          |        ZZ      ZZ
                                |        ZZ    ZZ        |          ZZ   ZZ
                                |       ZZ      ZZ       |           ZZ ZZ
                                |       ZZ      ZZ       |            ZZZ
                                |       ZZ      ZZ       |           ZZ ZZ
                                |        ZZ    ZZ        |          ZZ   ZZ
                                |          ZZZZ          |        ZZ      ZZ
                                |                        |
        ------------------------|------------------------|--------------------------
        ------------------------|------------------------|--------------------------
                                |                        |
                                |                        |
                                |                        |        ZZ      ZZ
                                |                        |          ZZ   ZZ
                                |                        |           ZZ ZZ
                                |                        |            ZZZ
                                |                        |           ZZ ZZ
                                |                        |          ZZ   ZZ
                                |                        |        ZZ      ZZ
                                |                        |




Please input position from 1-9:



```

```
                                |                        |
                                |                        |
              ZZ      ZZ        |          ZZZZ          |        ZZ      ZZ
                ZZ   ZZ         |        ZZ    ZZ        |          ZZ   ZZ
                 ZZ ZZ          |       ZZ      ZZ       |           ZZ ZZ
                  ZZZ           |       ZZ      ZZ       |            ZZZ
                 ZZ ZZ          |       ZZ      ZZ       |           ZZ ZZ
                ZZ   ZZ         |        ZZ    ZZ        |          ZZ   ZZ
              ZZ      ZZ        |          ZZZZ          |        ZZ      ZZ
                                |                        |
        ------------------------|------------------------|--------------------------
        ------------------------|------------------------|--------------------------
                                |                        |
                                |                        |
                 ZZZZ           |       ZZ      ZZ       |        ZZ      ZZ
               ZZ    ZZ         |         ZZ   ZZ        |          ZZ   ZZ
              ZZ      ZZ        |          ZZ ZZ         |           ZZ ZZ
              ZZ      ZZ        |           ZZZ          |            ZZZ
              ZZ      ZZ        |          ZZ ZZ         |           ZZ ZZ
               ZZ    ZZ         |         ZZ   ZZ        |          ZZ   ZZ
                 ZZZZ           |       ZZ      ZZ       |        ZZ      ZZ
                                |                        |
        ------------------------|------------------------|--------------------------
        ------------------------|------------------------|--------------------------
                                |                        |
                                |                        |
                 ZZZZ           |       ZZ      ZZ       |           ZZZZ
               ZZ    ZZ         |         ZZ   ZZ        |         ZZ    ZZ
              ZZ      ZZ        |          ZZ ZZ         |        ZZ      ZZ
              ZZ      ZZ        |           ZZZ          |        ZZ      ZZ
              ZZ      ZZ        |          ZZ ZZ         |        ZZ      ZZ
               ZZ    ZZ         |         ZZ   ZZ        |         ZZ    ZZ
                 ZZZZ           |       ZZ      ZZ       |           ZZZZ
                                |                        |




 ________      ________      ________      ___       __           ___
|\   ___ \    |\   __  \    |\   __  \    |\  \     |\  \        |\  \
\ \  \_|\ \   \ \  \|\  \   \ \  \|\  \   \ \  \    \ \  \       \ \  \
 \ \  \ \\ \   \ \   _  _\   \ \   __  \   \ \  \  __\ \  \       \ \  \
  \ \  \_\\ \   \ \  \\  \|   \ \  \ \  \   \ \  \|\__\_\  \       \ \__\
   \ \_______\   \ \__\\ _\    \ \__\ \__\   \ \____________\       \|__|
    \|_______|    \|__|\|__|    \|__|\|__|    \|____________|           ___
                                                                       |\__\
                                                                       \|__|


Wanna play again? [y|n]:
```
