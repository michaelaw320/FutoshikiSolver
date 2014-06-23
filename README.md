FutoshikiSolver
===============

Simple 5x5 Futoshiki Solver for Windows

===============

How to use:
- Edit the input.txt
- -1 for >
- -2 for <
- -3 for no inequality
- 0 for empty cells
- Numbers for the value

Example : 

0	>	0		0	>	0	>	0	

4		0		0		0		2	
	
0		0		4		0		0	
	
0		0		0		0	<	4	
	
0	<	0	<	0		0		0

where 0 reads as blanks that need to be filled

turns into this for input.txt :

0	-1	0	-3	0	-1	0	-1	0	
-3	-3	-3	-3	-3	-3	-3	-3	-3	
4	-3	0	-3	0	-3	0	-3	2	
-3	-3	-3	-3	-3	-3	-3	-3	-3	
0	-3	0	-3	4	-3	0	-3	0	
-3	-3	-3	-3	-3	-3	-3	-3	-3	
0	-3	0	-3	0	-3	0	-2	4	
-3	-3	-3	-3	-3	-3	-3	-3	-3	
0	-2	0	-2	0	-3	0	-3	0

