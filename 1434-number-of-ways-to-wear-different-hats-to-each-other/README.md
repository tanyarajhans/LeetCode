<h2><a href="https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/">1434. Number of Ways to Wear Different Hats to Each Other</a></h2><h3>Hard</h3><hr><div class=""><p class="">There are <code class="">n</code> people and <code class="">40</code> types of hats labeled from <code class="">1</code> to <code class="">40</code>.</p>

<p class="">Given a 2D integer array <code class="">hats</code>, where <code class="">hats[i]</code> is a list of all hats preferred by the <code class="">i<sup class="">th</sup></code> person.</p>

<p class="">Return <em class="">the number of ways that the <code class="">n</code> people wear different hats to each other</em>.</p>

<p class="">Since the answer may be too large, return it modulo <code class="">10<sup class="">9</sup> + 7</code>.</p>

<p class="">&nbsp;</p>
<p class=""><strong class="">Example 1:</strong></p>

<pre class=""><strong class="">Input:</strong> hats = [[3,4],[4,5],[5]]
<strong class="">Output:</strong> 1
<strong class="">Explanation:</strong> There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.
</pre>

<p class=""><strong class="">Example 2:</strong></p>

<pre class=""><strong class="">Input:</strong> hats = [[3,5,1],[3,5]]
<strong class="">Output:</strong> 4
<strong class="">Explanation:</strong> There are 4 ways to choose hats:
(3,5), (5,3), (1,3) and (1,5)
</pre>

<p class=""><strong class="">Example 3:</strong></p>

<pre class=""><strong class="">Input:</strong> hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
<strong class="">Output:</strong> 24
<strong class="">Explanation:</strong> Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.
</pre>

<p class="">&nbsp;</p>
<p class=""><strong class="">Constraints:</strong></p>

<ul class="">
	<li class=""><code class="">n == hats.length</code></li>
	<li class=""><code class="">1 &lt;= n &lt;= 10</code></li>
	<li class=""><code class="">1 &lt;= hats[i].length &lt;= 40</code></li>
	<li class=""><code class="">1 &lt;= hats[i][j] &lt;= 40</code></li>
	<li class=""><code class="">hats[i]</code> contains a list of <strong class="">unique</strong> integers.</li>
</ul>
</div>