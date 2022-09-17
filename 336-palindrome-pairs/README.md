<h2><a href="https://leetcode.com/problems/palindrome-pairs/">336. Palindrome Pairs</a></h2><h3>Hard</h3><hr><div><p>Given a list of <b>unique</b> words, return all the pairs of the&nbsp;<b><i>distinct</i></b> indices <code>(i, j)</code> in the given list, so that the concatenation of the two words&nbsp;<code>words[i] + words[j]</code> is a palindrome.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["abcd","dcba","lls","s","sssll"]
<strong>Output:</strong> [[0,1],[1,0],[3,2],[2,4]]
<strong>Explanation:</strong> The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["bat","tab","cat"]
<strong>Output:</strong> [[0,1],[1,0]]
<strong>Explanation:</strong> The palindromes are ["battab","tabbat"]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["a",""]
<strong>Output:</strong> [[0,1],[1,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>0 &lt;= words[i].length &lt;= 300</code></li>
	<li><code>words[i]</code> consists of lower-case English letters.</li>
</ul>
</div>