<h2>407. Trapping Rain Water II</h2><h3>Hard</h3><hr><div><p>Given an <code>m x n</code> integer matrix <code>heightMap</code> representing the height of each unit cell in a 2D elevation map, return <em>the volume of water it can trap after raining</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/trap1-3d.jpg" style="width: 361px; height: 321px;">
<pre><strong>Input:</strong> heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/trap2-3d.jpg" style="width: 401px; height: 321px;">
<pre><strong>Input:</strong> heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
<strong>Output:</strong> 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == heightMap.length</code></li>
	<li><code>n == heightMap[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= heightMap[i][j] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>
</div>