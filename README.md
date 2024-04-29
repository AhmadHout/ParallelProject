# ParallelProject

Description of the application to be parallelized:
The queen is to be placed in different columns, beginning at the leftmost column. When we're placing a queen in a column, we'll check to see if there's a conflict with the queens we've already placed. If we find a row where there's no conflict, we'll mark that row and column as part of the solution in the current column. If we do not find such a row due to clashes, then we backtrack and return false.

Why was this code parallelized?
The N-Queens problem has been in the field of study for several decades in computer science. The studies always aim to enhance the code or to make it run faster and more efficient, sequentially. Until recently, parallelization techniques have been introduced and have made this problem run in faster and more efficient ways. We wanted to parallelize this code to help in continuing this study and further try to enhance it. We are parallelizing the N-Queens problem to keep improving how fast and efficient it runs. By doing this, we're joining in on this effort to keep making progress and finding better ways to solve the N-Queens problem.


Concercning the parallelization of n queens using Open ACC, it should be noted that our method of implementation which relies mainly on recursion. Recursion in GPU programming frequently results in decreased performance because of the extra work involved in handling the call stack and memory. Instead, running the code sequentially inside the top loops might be better.
