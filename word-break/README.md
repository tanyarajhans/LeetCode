<h2>139. Word Break</h2><h3>Medium</h3><hr><div><p>Given a <strong>non-empty</strong> string <em>s</em> and a dictionary <em>wordDict</em> containing a list of <strong>non-empty</strong> words, determine if <em>s</em> can be segmented into a space-separated sequence of one or more dictionary words.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The same word in the dictionary may be reused multiple times in the segmentation.</li>
	<li>You may assume the dictionary does not contain duplicate words.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because <code>"leetcode"</code> can be segmented as <code>"leet code"</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because <code>"</code>applepenapple<code>"</code> can be segmented as <code>"</code>apple pen apple<code>"</code>.
&nbsp;            Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>Output:</strong> false
</pre>
</div>