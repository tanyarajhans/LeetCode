<h2>81. Search in Rotated Sorted Array II</h2><h3>Medium</h3><hr><div><p>You are given an integer array <code>nums</code> sorted in ascending order (not necessarily <strong>distinct</strong> values), and an integer <code>target</code>.</p>

<p>Suppose that <code>nums</code> is rotated at some pivot unknown to you beforehand (i.e., <code>[0,1,2,4,4,4,5,6,6,7]</code> might become <code>[4,5,6,6,7,0,1,2,4,4]</code>).</p>

<p><em>If <code>target</code> is found in the array return its index, otherwise, return <code>-1</code>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,5,6,0,0,1,2], target = 0
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,5,6,0,0,1,2], target = 3
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is guaranteed to be rotated at some pivot.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up: </strong>This problem is the same as <a href="/problems/search-in-rotated-sorted-array/description/" target="_blank">Search in Rotated Sorted Array</a>, where <code>nums</code> may contain <strong>duplicates</strong>. Would this affect the run-time complexity? How and why?</div>