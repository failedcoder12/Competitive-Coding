Bob and Editor

Bob is working on his college project. He tried to make an editor like Vim, but he came up with some messed editor which will follow only following commands :

    dd  -- delete the current line and move the cursor to the end of next line. If there is no next line, move the cursor to end of the previous line. If all the lines are deleted, move the cursor to the start of the first line.

    :m  -- move the cursor to the end of line m

    i m -- each following m lines contain text to insert.

    y -- copy the current line and replace the content of the buffer with the copied line.

    p -- paste the content of the buffer (the copied line) at the end of the current line and move the cursor to the end of the line. If no line is copied, ignore this command.

    dy -- it will work similar to command dd and also copy the deleted line and replace the content of the buffer with the copied line.

You are given some initial text T and Q commands. You are required to print the final text after applying the given commands on T. Initially, the cursor is present at the end of the last line and the buffer is empty.

Input :

    The first line of input contains an integer N, number of lines in the initial text T.
    Next N lines contain the content of T.
    Next line contains Q, denoting the number of commands.
    It is followed by Q commands.

Output :

    Print the final text T after applying the Q commands.

Constraints :

1<= N <= 100
1<= Q <= 100
Number of characters in T does not exceed 1100

Sample Input

2

Nikunj

Khokhar

6

dd

dd

i 2

Yes

NO

:1

dd

i 2

No WAY

BETTER OPTIOn

Sample Output

NONo WAY

BETTER OPTIOn

Explanation

Initial text T is

Nikunj
Khokhar

The first command is dd which will delete the last line. So the text T will be

Nikunj

The second command is dd which will delete the one line and the cursor will move to the start of the first line since all the lines are deleted.

The third command is i 2, which will add the next two lines in the text T. So the text T will be

Yes

NO

The next command is :1 which will move the cursor to the end of the first line.

The next command is dd which will delete the first line and the cursor will move to the end of next line. So the text T will be

NO

The last command is i 2 which will add the next two line in the text. So the text T will be

NONo WAY

BETTER OPTIOn

NOTE: There are multiple input files and the time limit is 1 sec for each input file.
Note: Your code should be able to convert the sample input into the sample output. However, this is not enough to pass the challenge, because the code will be run on multiple test cases. Therefore, your code must solve this problem statement.




Unlock Pattern

Boogle, the software giant developed a mobile operating system named Ambroid. As we all know, in order to unlock an Ambroid device, one needs to draw a pattern connecting the given dots. The developers of Ambroid OS want this pattern unlock to be more secure. So they are wondering, in how many ways, can we draw a pattern by connecting dots.

Given N points (dots) in the co-ordinate system, find and return the number of ways in which, we can draw a pattern by connecting dots.

A pattern is a sequence of distinct dots where two adjacent dots in the sequence are connected by a line segment and should satisfy following conditions.

    A pattern should connect at least two dots.
    While connecting two dots A and B, suppose there is a dot C which has not yet been connected and lies on the line segment joining A and B, then you cannot connect A and B without connecting C in between, that is, pattern A-C-B and pattern B-C-A are valid but the patterns A-B or B-A are not valid as C has not yet been connected.
    Note that patterns C-A-B and C-B-A are also valid as while connecting A-B or B-A in these patterns, C has already been connected.

Eg : Suppose A(0,0) , B(0,2), C(2,0) and D(1,1) be the four dots. Then A-C-B is not a valid pattern because while connecting C and B, D lies in between which has not yet been connected. Note that D-A-C-B is a valid pattern (because D has already been connected)

Input
First line consists of an integer N which denotes the number of points (dots).
Each of next N lines contains two space separated integers (denoting a point): first integer represents the x coordinate and second represents y coordinate of the point.

Output
Print the answer as described in the problem statement.

Constraints

2<= N <=16
0<= x,y <=200
all points are distinct


All points are distinct
Sample Input

3

0 0

1 0

2 0

Sample Output

8

Explanation

let the points be A(0,0) and B(1,0) and C(2,0).
 

Then following are valid patterns.
A-B
A-B-C
B-A
B-A-C (since B is already connected)
B-C-A (since B is already connected)
C-B
C-B-A