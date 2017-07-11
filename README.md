# stingy-point-sequence

This code implements an algorithm proposed by Christian Remling for sequentially adding points on a circle so that the first N points have no pair that is at a distance less than mu/N.

See https://mathoverflow.net/questions/275158/sequential-addition-of-points-on-a-circle-optimizing-asymptotic-packing-radius

To compile, use the following command line, or its equivalent on your machine:

> $ g++ -o stingy.out stingy.cpp -lgmp -lgmpxx -O3

To run, supply a rational number as the parameter mu:

> % ./stingy.out 71/100
