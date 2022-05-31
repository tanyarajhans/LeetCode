# Implement Queue using array
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Implement a Queue using an Array. Queries in the Queue are of the following type:<br>
<strong>(i)</strong>&nbsp;1 x&nbsp; &nbsp;(a query of this type means&nbsp;&nbsp;pushing&nbsp;<strong>'x'</strong>&nbsp;into the queue)<br>
<strong>(ii)</strong>&nbsp;2 &nbsp; &nbsp; (a query of this type means to pop&nbsp;element from queue and print the poped element)</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>Q = 5
Queries = 1 2 1 3 2 1 4 2
<strong>Output: </strong>2&nbsp;3<strong>
Explanation:
</strong>In the first test case for query&nbsp;
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2 &nbsp; poped element will be 2 the 
    queue will be {3}
1 4 the queue will be {3 4}
2 &nbsp; poped element will be 3&nbsp;</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>Q = 4
Queries = 1 3 2 2 1 4 &nbsp; 
<strong>Output: </strong>3 -1<strong>
Explanation:
</strong>In the second testcase for query&nbsp;
1 3 the queue will be {3}
2&nbsp; &nbsp;poped element will be 3 the
&nbsp;   queue will be empty
2&nbsp; &nbsp;there is no element in the
&nbsp;   queue and hence -1
1 4 the queue will be {4}.&nbsp;</span></pre>

<p><span style="font-size:18px"><strong>Your Task :</strong><br>
You are required to complete the two methods&nbsp;<strong>push()</strong>&nbsp;which take one argument an integer&nbsp;<strong>'x'</strong>&nbsp;to be pushed into the queue&nbsp;and&nbsp;<strong>pop()</strong>&nbsp;which <strong>returns </strong>a <strong>integer&nbsp;</strong>poped out from othe queue. If the queue is empty, it should return -1 on a pop operation.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for both&nbsp;<strong>push()&nbsp;</strong>and&nbsp;<strong>pop()</strong>.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1) for both&nbsp;<strong>push()&nbsp;</strong>and&nbsp;<strong>pop()</strong>.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ Q ≤ 10<sup>5</sup><br>
1 ≤ x<strong> </strong>≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>