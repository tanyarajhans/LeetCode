# Flattening a Linked List
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:<br>
(i) a<strong> next </strong>pointer to the next node,<br>
(ii) a<strong>&nbsp;bottom</strong>&nbsp;pointer&nbsp;to a linked list where this node is head.<br>
Each of the&nbsp;sub-linked-list is in sorted order.<br>
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.&nbsp;</span><br>
<span style="font-size:18px"><strong>Note:</strong> The flattened list will be printed using the bottom pointer instead of next pointer.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>5 -&gt; 10 -&gt; 19 -&gt; 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45<strong>
Output: </strong>&nbsp;5-&gt; 7-&gt; 8- &gt; 10 -&gt; 19-&gt; 20-&gt;
22-&gt; 28-&gt; 30-&gt; 35-&gt; 40-&gt; 45-&gt; 50.
<strong>Explanation</strong>:
The resultant linked lists has every 
node in a single level.<strong>
</strong>(<strong>Note: </strong>| represents the bottom pointer.)</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
5 -&gt; 10 -&gt; 19 -&gt; 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
<strong>Output:</strong> 5-&gt;7-&gt;8-&gt;10-&gt;19-&gt;22-&gt;28-&gt;30-&gt;50
<strong>Explanation:</strong>
The resultant linked lists has every
node in a single level.

(<strong>Note: </strong>| represents the bottom pointer.)</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Complete the function <strong>flatten()</strong></span><span style="font-size:18px"> that takes the&nbsp;<strong>head </strong>of the linked list as input&nbsp;parameter<strong> </strong>and returns the head of flattened link list.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*N*M)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">0 &lt;= N &lt;= 50<br>
1 &lt;=<strong> M<sub>i</sub> </strong>&lt;= 20<br>
1 &lt;= Element of linked list &lt;= 10<sup>3</sup></span></p>
 <p></p>
            </div>