<h2>477. Total Hamming Distance</h2><h3>Medium</h3><hr><div><p>The <a href="https://en.wikipedia.org/wiki/Hamming_distance" target="_blank">Hamming distance</a> between two integers is the number of positions at which the corresponding bits are different.</p>

<p>Now your job is to find the total Hamming distance between all pairs of the given numbers.


</p><p><b>Example:</b><br>
</p><pre><b>Input:</b> 4, 14, 2

<b>Output:</b> 6

<b>Explanation:</b> In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>Elements of the given array are in the range of <code>0 </code> to <code>10^9</code>
</li><li>Length of the array will not exceed <code>10^4</code>. </li>
</ol>
<p></p></div>