Project 3 Minix Disk Program


Group A
    Alexander DeCamillo
    Sarah Alzahrani


Contributions
    Alex 80%
    Sarah 20%


Summary
This project was to simulate the mounting and exploration of a minix disk image.
The project involved using system calls such as open(), read(), write(), lseek(),
and close() to read in the data from the disk. With the given structs from the
lecture slides, we were able to read the data in as structured data that is usable.
This is necessary because the data being read is the not readable on the disk.
These structures were used to display the information requested by the user. The
console interface was an infinite while loop that asks for input each iteration.
Upon receiving input, the input string is parsed to see arguments and then sent
to a function that determines which module to run. All of the modules are in the
modules.c file. All of the modules work as intended.


Compilation Instructions
run the command 'make' followed by './MinixConsole'


Module Descriptions
minimount: Uses the open() call to create a file descriptor from the provided imagefile

miniumount: Uses the close() call to close the current file descriptor

showsuper: Uses lseek() to move to the 2nd block and then reads the data in as
    a minix_super_block struct. Then the modules displays the data

traverse: Grabs the root inode and moves to each of it's data zones. Then the module
    reads the data in as a minix_dir_entry struct. The name of the file is then
    displayed. If the "-l" or "long list" argument is used, the inumber is taken
    from this entry and is used to get the inode for that file. After reading in
    the inode, you can display the file/directroy data as well.

showzone: moves the offset to the requested zone and then reads in data a byte at
    a time and prints it out

showfile: works in the same way that the traverse modules does in terms of finding
    an inode for a given filename. When the inode is found, the offset is moved to
    the data zones and prints off the data as a hexadecimal number. This is called
    a hex dump

help: displays the possible commands

quit: exits the minix console


Sample Run of modules
Minix Console$ minimount imagefile.img
Image sucessfully mounted
Minix Console$ showfile PolyTest.jav

   61   62   73   74   72   61   63   74   20   63   6c   61   73   73   20   41
   20   7b    a    9   70   75   62   6c   69   63   20   61   62   73   74   72
   61   63   74   20   76   6f   69   64   20   67   65   6f   28   29   3b    a
    9   70   75   62   6c   69   63   20   76   6f   69   64   20   6c   6f   75
   28   29   20   7b   65   63   68   6f   28   22   41   2e   6c   6f   75   22
   29   3b   67   65   6f   28   29   3b   7d    a    9   70   75   62   6c   69
   63   20   76   6f   69   64   20   6d   61   72   79   28   29   20   7b   65
   63   68   6f   28   22   41   2e   6d   61   72   79   22   29   3b   20   6d
   75   72   72   61   79   28   29   3b   7d    a    9   70   75   62   6c   69
   63   20   73   74   61   74   69   63   20   76   6f   69   64   20   6d   75
   72   72   61   79   28   29   20   7b   65   63   68   6f   28   22   41   2e
   6d   75   72   72   61   79   22   29   3b   7d    a    9   70   75   62   6c
   69   63   20   76   6f   69   64   20   74   65   64   28   29   20   7b   65
   63   68   6f   28   22   41   2e   74   65   64   22   29   3b   7d    a    9
   70   72   6f   74   65   63   74   65   64   20   73   74   61   74   69   63
   20   76   6f   69   64   20   65   63   68   6f   28   53   74   72   69   6e
   67   20   74   65   78   74   29   20   7b   53   79   73   74   65   6d   2e
   6f   75   74   2e   70   72   69   6e   74   6c   6e   28   74   65   78   74
   29   3b   7d    a   7d    a    a   63   6c   61   73   73   20   42   20   65
   78   74   65   6e   64   73   20   41   20   7b    a    9   70   75   62   6c
   69   63   20   76   6f   69   64   20   67   65   6f   28   29   20   7b   65
   63   68   6f   28   22   42   2e   67   65   6f   22   29   3b   20   6d   61
   72   79   28   29   3b   7d    a    9   70   75   62   6c   69   63   20   73
   74   61   74   69   63   20   76   6f   69   64   20   6d   75   72   72   61
   79   28   29   20   7b   65   63   68   6f   28   22   42   2e   6d   75   72
   72   61   79   22   29   3b   7d    a   7d    a    a   61   62   73   74   72
   61   63   74   20   63   6c   61   73   73   20   43   20   65   78   74   65
   6e   64   73   20   41   20   7b    a    9   70   75   62   6c   69   63   20
   76   6f   69   64   20   6d   61   72   79   28   29   20   7b   65   63   68
   6f   28   22   43   2e   6d   61   72   79   22   29   3b   20   74   65   64
   28   29   3b   20   7d    a    9   70   75   62   6c   69   63   20   73   74
   61   74   69   63   20   76   6f   69   64   20   6d   75   72   72   61   79
   28   29   20   7b   65   63   68   6f   28   22   43   2e   6d   75   72   72
   61   79   22   29   3b   7d    a    9   70   75   62   6c   69   63   20   76
   6f   69   64   20   74   65   64   28   29   20   7b   65   63   68   6f   28
   22   43   2e   74   65   64   22   29   3b   20   6d   75   72   72   61   79
   28   29   3b   7d    a   7d    a    a   63   6c   61   73   73   20   44   20
   65   78   74   65   6e   64   73   20   43   20   7b    a    9   70   75   62
   6c   69   63   20   76   6f   69   64   20   67   65   6f   28   29   20   7b
   65   63   68   6f   28   22   44   2e   67   65   6f   22   29   3b   20   6d
   61   72   79   28   29   3b   7d    a    9   70   75   62   6c   69   63   20
   76   6f   69   64   20   6c   6f   75   28   29   20   7b   65   63   68   6f
   28   22   44   2e   6c   6f   75   22   29   3b   73   75   70   65   72   2e
   6c   6f   75   28   29   3b   7d    a    9   70   75   62   6c   69   63   20
   73   74   61   74   69   63   20   76   6f   69   64   20   6d   75   72   72
   61   79   28   29   20   7b   65   63   68   6f   28   22   44   2e   6d   75
   72   72   61   79   22   29   3b   7d    a    9   70   75   62   6c   69   63
   20   76   6f   69   64   20   74   65   64   28   29   20   7b   65   63   68
   6f   28   22   44   2e   74   65   64   22   29   3b   20   73   75   70   65
   72   2e   74   65   64   28   29   3b   7d    a   7d    a    a   70   75   62
   6c   69   63   20   63   6c   61   73   73   20   50   6f   6c   79   54   65
   73   74   20   7b    a    9   73   74   61   74   69   63   20   76   6f   69
   64   20   54   65   73   74   28   41   20   6f   62   6a   29   20   7b    a
    9    9   6f   62   6a   2e   6d   75   72   72   61   79   28   29   3b    a
    9    9   6f   62   6a   2e   6c   6f   75   28   29   3b    a    9   7d    a
    9   70   75   62   6c   69   63   20   73   74   61   74   69   63   20   76
   6f   69   64   20   6d   61   69   6e   28   53   74   72   69   6e   67   20
   5b   5d   20   61   72   67   73   29   20   7b    a    9    9   42   20   62
   20   3d   20   6e   65   77   20   42   28   29   3b    a    9    9   50   6f
   6c   79   54   65   73   74   2e   54   65   73   74   28   62   29   3b    a
    9    9    a    9    9   53   79   73   74   65   6d   2e   6f   75   74   2e
   70   72   69   6e   74   6c   6e   28   22   2a   2a   2a   2a   2a   2a   2a
   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a   2a
   2a   2a   2a   2a   2a   2a   2a   2a   2a   22   29   3b    a    9    9   44

   20   64   20   3d   20   6e   65   77   20   44   28   29   3b    a    9    9
   50   6f   6c   79   54   65   73   74   2e   54   65   73   74   28   64   29
   3b    a    9   7d    a   7d    a    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
Minix Console$ showzone 114
      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f

   0                       2     >
  10              !        "        #        $
  20  %        &        '        (        )        *
  30        +        ,        -              .
  40  /     0        1     2        3        4
  50     <  i  n  i  t  >           (  )  V
  60  C  o  d  e           L  i  n  e  N  u  m  b  e
  70  r  T  a  b  l  e           m  a  i  n
  80  (  [  L  j  a  v  a  /  l  a  n  g  /  S  t  r
  90  i  n  g  ;  )  V           S  t  a  c  k  M  a
  a0  p  T  a  b  l  e        5           S  o  u  r
  b0  c  e  F  i  l  e           A  l  o  o  p  1  .
  c0  j  a  v  a                          j  a  v  a
  d0  /  l  a  n  g  /  S  t  r  i  n  g           D
  e0  E  U  C  E           T  H  R  E  E           F
  f0  O  U  R           F  I  V  E           S  I  X
 100           S  E  V  E  N           E  I  G  H  T
 110           N  I  N  E           T  E  N
 120  J  A  C  K           Q  U  E  E  N           K
 130  I  N  G           A  C  E        6     7
 140  8        9     :        ;        <     =
 150     A  l  o  o  p  1           j  a  v  a  /  l
 160  a  n  g  /  O  b  j  e  c  t           [  L  j
 170  a  v  a  /  l  a  n  g  /  S  t  r  i  n  g  ;
 180           e  q  u  a  l  s           (  L  j  a
 190  v  a  /  l  a  n  g  /  O  b  j  e  c  t  ;  )
 1a0  Z           j  a  v  a  /  l  a  n  g  /  S  y
 1b0  s  t  e  m           o  u  t           L  j  a
 1c0  v  a  /  i  o  /  P  r  i  n  t  S  t  r  e  a
 1d0  m  ;           j  a  v  a  /  i  o  /  P  r  i
 1e0  n  t  S  t  r  e  a  m           p  r  i  n  t
 1f0  l  n           (  I  )  V     !
 200
 210                                   *
 220
 230
 240                 n                 Y           S
 250  Y           S  Y           S  Y           S  Y
 260           S  Y           S  Y              S  Y
 270              S  Y              S  Y
 280  S  Y              S  Y              S  Y
 290        S  L     =     >  +     2
 2a0
 2b0                                         "
 2c0                 N           P           R
 2d0     ]           `           f           m
 2e0                                R
 2f0
 300
 310
 320
 330
 340
 350
 360
 370
 380
 390
 3a0
 3b0
 3c0
 3d0
 3e0
 3f0
Minix Console$ showsuper
number of inodes:       3424
number of zones:        10240
number of imap_blocks:  1
number of zmap_blocks:  2
first data zone:        112
log zone size: 	        0
max size: 	        268966912
magic: 	                5007
state:                  0
zones:                  0
Minix Console$ traverse
A.cla
Aloop1.cla
Aloop1.jav
Aloop2.cla
Aloop2.jav
Aloop3.cla
Aloop3.jav
B.cla
Condit.cla
Condit.jav
D.cla
Demo.cla
Demo.jav
dir1
PolyTest.cla
PolyTest.jav
some.cla
some.java
Minix Console$ traverse -l
-rw-rw-r-- 1000 670 Sep 20 2012  A.cla
-rw-r--r-- 1000 763 Dec 14 2010  Aloop1.cla
-rw-r--r-- 1000 333 Dec 14 2010  Aloop1.jav
-rw-r--r-- 1000 786 Dec 14 2010  Aloop2.cla
-rw-r--r-- 1000 404 Dec 14 2010  Aloop2.jav
-rw-r--r-- 1000 786 Dec 14 2010  Aloop3.cla
-rw-r--r-- 1000 408 Dec 14 2010  Aloop3.jav
-rw-rw-r-- 1000 358 Sep 20 2012  B.cla
-rw-r--r-- 1000 1067 Dec 14 2010  Condit.cla
-rw-r--r-- 1000 444 Dec 14 2010  Condit.jav
-rw-rw-r-- 1000 508 Sep 20 2012  D.cla
-rw-r--r-- 1000 967 Dec 14 2010  Demo.cla
-rw-r--r-- 1000 648 Dec 14 2010  Demo.jav
drwx------ 1000 128 Oct 27 2014  dir1
-rw-rw-r-- 1000 630 Sep 20 2012  PolyTest.cla
-rw-rw-r-- 1000 1063 Sep 20 2012  PolyTest.jav
-rw-r--r-- 1000 226 Dec 14 2010  some.cla
-rw-r--r-- 1000 278 Dec 14 2010  some.java
Minix Console$ help
-------------- COMMANDS --------------
  minimount
    DESCRIPTION:     Mount a local minix disk.
    USAGE:           minimount <imagefile>
  miniumount
    DESCRIPTION:     Unmounts the mounted minix disk.
    USAGE:           miniumount
  showsuper
    DESCRIPTION:     Lists the information of the super block
    USAGE:           showsuper
  traverse
    DESCRIPTION:     Lists the contents of the root directory, and prints detailed information if [-l] is on.
    USAGE:           traverse, traverse -l
  showzone
    DESCRIPTION:     Show the ASCII content of a specified zone number.
    USAGE:           showzone <zonenumber>
  help
    DESCRIPTION:     Displays all available commands.
    USGAE:           help
  showfile
    DESCRPTION:     Show the contents of a file.
    USAGE:          showfile <filename>
  quit
    DESCRIPTION:     quits minix shell.
    USAGE:           quit
Minix Console$ miniumount
Image sucessfully unmounted
Minix Console$ quit
