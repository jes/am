# Alphametic Solver

An alphametic is a puzzle in which a sum is expressed with the numbers changed
to letters. The puzzle is to find which number each letter corresponds to. This
program solves these puzzles.

There is a git repository at [github](http://github.com/jes/am).

  1. The puzzle
  2. Compiling
  3. Usage
  4. Contact

## 1. The puzzle

A sum is expressed with the numbers changed to letters.

For example:
  `SEND + MORE = MONEY`

The puzzle is to find out which digit S corresponds to, which one E corresponds
to, etc. There is the constraint that there are no leading 0's, and there is a
one-to-one mapping of letters to digits (each letter always means the same
digit, and each digit is always represented by the same letter).

## 2. Compiling

Compiling the program is very simple, just run  
  `$ make`  
and the file `am` will be created. This is the solver program, and you can run
it from where it is, or install it with  
  `$ make install`  

If you wish to install in to a different prefix, use, for example:  
  `$ make PREFIX=/usr/local install`  

You can also set DESTDIR, for example to install somewhere under /opt.

## 3. Usage

The interface is mostly fairly intuitive. To solve the puzzle given above,
run the program as  
  `$ am SEND + MORE = MONEY`  
and it will output the value to be used for each letter. If some digits are
given as part of the problem, just write them in:  
  `$ am S5N7 + MO8E = MO6EY`

The program can also cope with subtraction, but currently not multiplication or
division.

## 4. Contact

If you find a bug or just want to contact me for any reason, send an email to  
  James Stanley <james@incoherency.co.uk>  
or find me on IRC as the user `jamesstanley` on `irc.freenode.net`. I am
usually in the channel `#maximilian`, so you'll probably find me in there.
