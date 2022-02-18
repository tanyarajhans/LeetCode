<h2><a href="https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/">1170. Compare Strings by Frequency of the Smallest Character</a></h2><h3>Medium</h3><hr><div><p>Let the function <code>f(s)</code> be the <strong>frequency of the lexicographically smallest character</strong> in a non-empty string <code>s</code>. For example, if <code>s = "dcce"</code> then <code>f(s) = 2</code> because the lexicographically smallest character is <code>'c'</code>, which has a frequency of 2.</p>

<p>You are given an array of strings <code>words</code> and another array of query strings <code>queries</code>. For each query <code>queries[i]</code>, count the <strong>number of words</strong> in <code>words</code> such that <code>f(queries[i])</code> &lt; <code>f(W)</code> for each <code>W</code> in <code>words</code>.</p>

<p>Return <em>an integer array </em><code>answer</code><em>, where each </em><code>answer[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> queries = ["cbd"], words = ["zaaaz"]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") &lt; f("zaaaz").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> On the first query only f("bbb") &lt; f("aaaa"). On the second query both f("aaa") and f("aaaa") are both &gt; f("cc").
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 2000</code></li>
	<li><code>1 &lt;= words.length &lt;= 2000</code></li>
	<li><code>1 &lt;= queries[i].length, words[i].length &lt;= 10</code></li>
	<li><code>queries[i][j]</code>, <code>words[i][j]</code> consist of lowercase English letters.</li>
</ul>
</div>