<h2>44. Wildcard Matching</h2><h3>Hard</h3><hr><div><p>Given an input string (<code>s</code>) and a pattern (<code>p</code>), implement wildcard pattern matching with support for <code>'?'</code> and <code>'*'</code> where:</p>

<ul>
	<li><code>'?'</code> Matches any single character.</li>
	<li><code>'*'</code> Matches any sequence of characters (including the empty sequence).</li>
</ul>

<p>The matching should cover the <strong>entire</strong> input string (not partial).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aa", p = "a"
<strong>Output:</strong> false
<strong>Explanation:</strong> "a" does not match the entire string "aa".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aa", p = "*"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;'*' matches any sequence.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "cb", p = "?a"
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;'?' matches 'c', but the second letter is 'a', which does not match 'b'.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "adceb", p = "*a*b"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "acdcb", p = "a*c?b"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length, p.length &lt;= 2000</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
	<li><code>p</code> contains only lowercase English letters, <code>'?'</code> or <code>'*'</code>.</li>
</ul>
</div>