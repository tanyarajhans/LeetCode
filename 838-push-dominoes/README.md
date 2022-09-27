<h2><a href="https://leetcode.com/problems/push-dominoes/">838. Push Dominoes</a></h2><h3>Medium</h3><hr><div><p>There are <code>n</code> dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.</p>

<p>After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.</p>

<p>When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.</p>

<p>For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.</p>

<p>You are given a string <code>dominoes</code> representing the initial state where:</p>

<ul>
	<li><code>dominoes[i] = 'L'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the left,</li>
	<li><code>dominoes[i] = 'R'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the right, and</li>
	<li><code>dominoes[i] = '.'</code>, if the <code>i<sup>th</sup></code> domino has not been pushed.</li>
</ul>

<p>Return <em>a string representing the final state</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> dominoes = "RR.L"
<strong>Output:</strong> "RR.L"
<strong>Explanation:</strong> The first domino expends no additional force on the second domino.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 196px; width: 512px;">
<pre><strong>Input:</strong> dominoes = ".L.R...LR..L.."
<strong>Output:</strong> "LL.RR.LLRRLL.."
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == dominoes.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>dominoes[i]</code> is either <code>'L'</code>, <code>'R'</code>, or <code>'.'</code>.</li>
</ul>
</div>