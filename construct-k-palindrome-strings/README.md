<h2>1400. Construct K Palindrome Strings</h2><h3>Medium</h3><hr><div><p>Given a string <code>s</code> and an integer <code>k</code>. You should construct <code>k</code> non-empty <strong>palindrome</strong> strings using <strong>all the characters</strong> in <code>s</code>.</p>

<p>Return <em><strong>True</strong></em> if you can use all the characters in <code>s</code> to construct <code>k</code> palindrome strings or <em><strong>False</strong></em> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "annabelle", k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", k = 3
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to construct 3 palindromes using all the characters of s.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "true", k = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> The only possible solution is to put each character in a separate string.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "yzyzyzyzyzyzyzy", k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "cr", k = 7
<strong>Output:</strong> false
<strong>Explanation:</strong> We don't have enough characters in s to construct 7 palindromes.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li>All characters in <code>s</code> are lower-case English letters.</li>
	<li><code>1 &lt;= k &lt;= 10^5</code></li>
</ul></div>