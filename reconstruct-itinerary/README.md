<h2>332. Reconstruct Itinerary</h2><h3>Medium</h3><hr><div><p>Given a list of airline tickets represented by pairs of departure and arrival airports <code>[from, to]</code>, reconstruct the itinerary in order. All of the tickets belong to a man who departs from <code>JFK</code>. Thus, the itinerary must begin with <code>JFK</code>.</p>

<p><b>Note:</b></p>

<ol>
	<li>If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary <code>["JFK", "LGA"]</code> has a smaller lexical order than <code>["JFK", "LGB"]</code>.</li>
	<li>All airports are represented by three capital letters (IATA code).</li>
	<li>You may assume all tickets form at least one valid itinerary.</li>
	<li>One must use all the tickets once and only once.</li>
</ol>

<p><b>Example 1:</b></p>

<pre><code><strong>Input: </strong></code><code>[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]</code>
<strong>Output: </strong><code>["JFK", "MUC", "LHR", "SFO", "SJC"]</code>
</pre>

<p><b>Example 2:</b></p>

<pre><code><strong>Input: </strong></code><code>[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]</code>
<strong>Output: </strong><code>["JFK","ATL","JFK","SFO","ATL","SFO"]</code>
<strong>Explanation: </strong>Another possible reconstruction is <code>["JFK","SFO","ATL","JFK","ATL","SFO"]</code>.
&nbsp;            But it is larger in lexical order.
</pre>
</div>