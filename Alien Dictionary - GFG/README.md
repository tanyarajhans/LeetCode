# Alien Dictionary
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a sorted dictionary of an alien language having N words and&nbsp;k starting alphabets of standard dictionary. Find the order of characters in the alien language.<br>
<strong>Note:</strong>&nbsp;Many orders may be&nbsp;possible for a particular test case, thus&nbsp;you may return any valid order and&nbsp;output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"</span><span style="font-size:18px">}
<strong>Output:
</strong>1
<strong>Explanation:
</strong>Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>N = 3, K = 3
dict = {"caa","aaa","aab"}
<strong>Output:
</strong>1
<strong>Explanation:
</strong>Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>findOrder()&nbsp;</strong>which takes </span>&nbsp;<span style="font-size:18px">the string array dict[], its size N&nbsp;and the integer K as input parameter&nbsp;and returns a string denoting the order of characters in the alien language.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N * |S| + K) , where |S| denotes maximum length.<br>
<strong>Expected Space Compelxity:&nbsp;</strong>O(K)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N, M ≤ 300<br>
1 ≤ K&nbsp;≤ 26<br>
1 ≤ Length of words&nbsp;≤ 50</span></p>
 <p></p>
            </div>