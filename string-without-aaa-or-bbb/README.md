<h2>984. String Without AAA or BBB</h2><h3>Medium</h3><hr><div><p>Given two integers <code>a</code> and <code>b</code>, return <strong>any</strong> string <code>s</code> such that:</p>

<ul>
	<li><code>s</code> has length <code>a + b</code> and contains exactly <code>a</code> <code>'a'</code> letters, and exactly <code>b</code> <code>'b'</code> letters,</li>
	<li>The substring <code>'aaa'</code> does not occur in <code>s</code>, and</li>
	<li>The substring <code>'bbb'</code> does not occur in <code>s</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = 1, b = 2
<strong>Output:</strong> "abb"
<strong>Explanation:</strong> "abb", "bab" and "bba" are all correct answers.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = 4, b = 1
<strong>Output:</strong> "aabaa"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= a, b &lt;= 100</code></li>
	<li>It is guaranteed such an <code>s</code> exists for the given <code>a</code> and <code>b</code>.</li>
</ul>
</div>