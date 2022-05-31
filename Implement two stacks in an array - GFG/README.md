# Implement two stacks in an array
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Your task is to implement&nbsp;&nbsp;2 stacks in one array efficiently.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>push1(2)
push1(3)
push2(4)
pop1()
pop2()<strong>
</strong>pop2()

<strong>Output:
</strong>3 4 -1<strong>

Explanation:
</strong>push1(2) the stack1&nbsp;will be {2}
push1(3) the stack1&nbsp;will be {2,3}
push2(4) the stack2 will be {4}
pop1() &nbsp; the&nbsp;poped element will be 3&nbsp;
from stack1 and stack1 will be {2}
pop2() &nbsp; the poped element will be 4&nbsp;
from stack2 and now stack2 is empty
pop2()&nbsp;  the stack2 is now empty hence -1 .</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">You don't need to read input or print anything.&nbsp;You are required to complete the 4&nbsp;methods&nbsp;<strong>push1,&nbsp;push2&nbsp;</strong>which takes one argument an integer<strong> 'x' </strong>to be pushed into stack one and two<strong>&nbsp;</strong>and&nbsp;<strong>pop1, pop2</strong>&nbsp;which returns the integer&nbsp;poped out from stack one and two. If no integer is present in the array return -1.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for all the four methods.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1) for all the four methods.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;=<strong> </strong>Number of queries &lt;= 100<br>
1 &lt;= value in the stack&nbsp;&lt;= 100</span><br>
<span style="font-size:18px">The sum of elements in both the stacks &lt; size of the given array</span></p>
 <p></p>
            </div>