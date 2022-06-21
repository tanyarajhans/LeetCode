# Rat in a Maze Problem - I
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Consider a rat placed at <strong>(0, 0)</strong> in a square matrix<strong> </strong>of order <strong>N * N</strong>. It has to reach the destination at <strong>(N - 1, N - 1)</strong>. Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are <strong>'U'(up)</strong>, <strong>'D'(down)</strong>, <strong>'L' (left)</strong>, <strong>'R' (right)</strong>. Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that&nbsp;rat&nbsp;can be travel&nbsp;through it.<br>
<strong>Note</strong>: In a path, no cell can be visited more than one time.</span>&nbsp;<span style="font-size:18px">If the source cell is&nbsp;0, the rat cannot move to any other cell.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
<strong>Output:</strong>
DDRDRR DRDDRR</span>
<span style="font-size:18px"><strong>Explanation</strong>:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.</span></pre>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input</strong>:
N = 2
m[][] = {{1, 0},
         {1, 0}}
<strong>Output:</strong>
-1</span>
<span style="font-size:18px"><strong>Explanation</strong>:
No path exists and destination cell is 
blocked.</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong>printPath()&nbsp;</strong>which takes <strong>N </strong>and 2D&nbsp;array<strong> m[ ][ ]</strong><strong> </strong>as input parameters and returns the list of&nbsp;paths in lexicographically increasing order.</span>&nbsp;<br>
<span style="font-size:18px"><strong>Note:</strong>&nbsp;In case of no path, return an empty list. The driver will output <strong>"-1"</strong> automatically.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O((3<sup>N</sup><sup>^2</sup>)).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(L * X), L = length of the path, X = number of paths.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ N ≤ 5<br>
0 ≤ m[i][j] ≤ 1</span></p>
 <p></p>
            </div>