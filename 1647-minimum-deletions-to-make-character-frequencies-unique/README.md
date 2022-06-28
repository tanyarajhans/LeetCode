<h2><a href="https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/">1647. Minimum Deletions to Make Character Frequencies Unique</a></h2><h3>Medium</h3><hr><div><p>A string <code>s</code> is called <strong>good</strong> if there are no two different characters in <code>s</code> that have the same <strong>frequency</strong>.</p>

<p>Given a string <code>s</code>, return<em> the <strong>minimum</strong> number of characters you need to delete to make </em><code>s</code><em> <strong>good</strong>.</em></p>

<p>The <strong>frequency</strong> of a character in a string is the number of times it appears in the string. For example, in the string <code>"aab"</code>, the <strong>frequency</strong> of <code>'a'</code> is <code>2</code>, while the <strong>frequency</strong> of <code>'b'</code> is <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> 0
<strong>Explanation:</strong> <code>s</code> is already good.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaabbbcc"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "ceabaacb"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;contains only lowercase English letters.</li>
</ul>
</div>