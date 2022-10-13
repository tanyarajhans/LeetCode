<h2><a href="https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/">1368. Minimum Cost to Make at Least One Valid Path in a Grid</a></h2><h3>Hard</h3><hr><div><p>Given an <code>m x n</code> grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of <code>grid[i][j]</code> can be:</p>

<ul>
	<li><code>1</code> which means go to the cell to the right. (i.e go from <code>grid[i][j]</code> to <code>grid[i][j + 1]</code>)</li>
	<li><code>2</code> which means go to the cell to the left. (i.e go from <code>grid[i][j]</code> to <code>grid[i][j - 1]</code>)</li>
	<li><code>3</code> which means go to the lower cell. (i.e go from <code>grid[i][j]</code> to <code>grid[i + 1][j]</code>)</li>
	<li><code>4</code> which means go to the upper cell. (i.e go from <code>grid[i][j]</code> to <code>grid[i - 1][j]</code>)</li>
</ul>

<p>Notice that there could be some signs on the cells of the grid that point outside the grid.</p>

<p>You will initially start at the upper left cell <code>(0, 0)</code>. A valid path in the grid is a path that starts from the upper left cell <code>(0, 0)</code> and ends at the bottom-right cell <code>(m - 1, n - 1)</code> following the signs on the grid. The valid path does not have to be the shortest.</p>

<p>You can modify the sign on a cell with <code>cost = 1</code>. You can modify the sign on a cell <strong>one time only</strong>.</p>

<p>Return <em>the minimum cost to make the grid have at least one valid path</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/13/grid1.png" style="width: 400px; height: 390px;">
<pre><strong>Input:</strong> grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --&gt; (0, 1) --&gt; (0, 2) --&gt; (0, 3) change the arrow to down with cost = 1 --&gt; (1, 3) --&gt; (1, 2) --&gt; (1, 1) --&gt; (1, 0) change the arrow to down with cost = 1 --&gt; (2, 0) --&gt; (2, 1) --&gt; (2, 2) --&gt; (2, 3) change the arrow to down with cost = 1 --&gt; (3, 3)
The total cost = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/13/grid2.png" style="width: 350px; height: 341px;">
<pre><strong>Input:</strong> grid = [[1,1,3],[3,2,2],[1,1,4]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> You can follow the path from (0, 0) to (2, 2).
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/13/grid3.png" style="width: 200px; height: 192px;">
<pre><strong>Input:</strong> grid = [[1,2],[4,3]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 4</code></li>
</ul>
</div>