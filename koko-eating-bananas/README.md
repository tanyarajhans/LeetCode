<h2>875. Koko Eating Bananas</h2><h3>Medium</h3><hr><div><p>Koko loves to eat bananas.&nbsp; There are <code>N</code>&nbsp;piles of bananas, the <code>i</code>-th&nbsp;pile has <code>piles[i]</code> bananas.&nbsp; The guards have gone and will come back in <code>H</code> hours.</p>

<p>Koko can decide her bananas-per-hour eating speed of <code>K</code>.&nbsp; Each hour, she chooses some pile of bananas, and eats K bananas from that pile.&nbsp; If the pile has less than <code>K</code> bananas, she eats all of them instead, and won't eat any more bananas during this hour.</p>

<p>Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.</p>

<p>Return the minimum integer <code>K</code> such that she can eat all the bananas within <code>H</code> hours.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> piles = [3,6,7,11], H = 8
<strong>Output:</strong> 4
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> piles = [30,11,23,4,20], H = 5
<strong>Output:</strong> 30
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> piles = [30,11,23,4,20], H = 6
<strong>Output:</strong> 23
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10^4</code></li>
	<li><code>piles.length &lt;= H &lt;= 10^9</code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10^9</code></li>
</ul>
</div>