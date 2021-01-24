<h2>424. Longest Repeating Character Replacement</h2><h3>Medium</h3><hr><div><p>Given a string <code>s</code>&nbsp;that consists of only uppercase English letters, you can perform at most <code>k</code> operations on that string.</p>

<p>In one operation, you can choose <strong>any</strong> character of the string and change it to any other uppercase English character.</p>

<p>Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.</p>

<p><b>Note:</b><br>
Both the string's length and <i>k</i> will not exceed 10<sup>4</sup>.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b>
s = "ABAB", k = 2

<b>Output:</b>
4

<b>Explanation:</b>
Replace the two 'A's with two 'B's or vice versa.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b>
s = "AABABBA", k = 1

<b>Output:</b>
4

<b>Explanation:</b>
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
</pre>

<p>&nbsp;</p>
</div>