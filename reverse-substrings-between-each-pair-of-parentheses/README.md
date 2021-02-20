<h2>1190. Reverse Substrings Between Each Pair of Parentheses</h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code> that consists of lower case English letters and brackets.&nbsp;</p>

<p>Reverse the strings&nbsp;in each&nbsp;pair of matching parentheses, starting&nbsp;from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any brackets.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(abcd)"
<strong>Output:</strong> "dcba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(u(love)i)"
<strong>Output:</strong> "iloveu"
<strong>Explanation:</strong>&nbsp;The substring "love" is reversed first, then the whole string is reversed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(ed(et(oc))el)"
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong>&nbsp;First, we reverse the substring "oc", then "etco", and finally, the whole string.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "a(bcdefghijkl(mno)p)q"
<strong>Output:</strong> "apmnolkjihgfedcbq"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It's guaranteed that all parentheses are balanced.</li>
</ul>
</div>