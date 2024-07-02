<h1>Ternary VS. If Runtime</h1>

To run the test, simply call ```make``` in the cloned folder and then run:

```./ternary [if | ternary] ${iterations}```

Where ```${iterations}``` simply means how many times you want the testing loop to run. The results are surprising :-)

Run example (in Bash™):

```
ITERATIONS=100000000000 && make && ./ternary if ${ITERATIONS} && ./ternary ternary ${ITERATIONS}
```

Output:

```
make: 'ternary' is up to date.
running program with op type: [if] and number: 100000000000
result was: 1932735283, total time was: 8.394028
running program with op type: [ternary] and number: 100000000000
result was: 1932735283, total time was: 9.000127
```
