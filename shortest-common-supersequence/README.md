<h2>1092. Shortest Common Supersequence </h2><h3>Hard</h3><hr><div><p>Given two strings <code>str1</code> and <code>str2</code>,&nbsp;return the shortest string that has both <code>str1</code>&nbsp;and <code>str2</code>&nbsp;as subsequences.&nbsp;&nbsp;If multiple answers exist, you may return any of them.</p>

<p><em>(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen <u>anywhere</u> from T) results in the string S.)</em></p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>str1 = <span id="example-input-1-1">"abac"</span>, str2 = <span id="example-input-1-2">"cab"</span>
<strong>Output: </strong><span id="example-output-1">"cabac"</span>
<strong>Explanation: </strong>
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> and <code>str2</code> consist of lowercase English letters.</li>
</ol>
</div>