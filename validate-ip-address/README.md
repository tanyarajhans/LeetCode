<h2>468. Validate IP Address</h2><h3>Medium</h3><hr><div><p>Given a string <code>IP</code>, return <code>"IPv4"</code> if IP is a valid IPv4 address,&nbsp;<code>"IPv6"</code> if&nbsp;IP is a valid IPv6 address or <code>"Neither"</code> if IP is not a correct IP of any type.</p>

<p><strong>A valid IPv4</strong> address&nbsp;is an IP in the form <code>"x<sub>1</sub>.x<sub>2</sub>.x<sub>3</sub>.x<sub>4</sub>"</code> where <code>0 &lt;=&nbsp;x<sub><span style="font-size: 10.8333px;">i</span></sub>&nbsp;&lt;= 255</code> and <code>x<sub>i</sub></code> <strong>cannot contain</strong> leading zeros. For example, <code>"192.168.1.1"</code> and&nbsp;<code>"192.168.1.0"</code> are valid IPv4 addresses but <code>"192.168.01.1"</code>, while <code>"192.168.1.00"</code>&nbsp;and <code>"192.168@1.1"</code> are invalid IPv4 addresses.</p>

<p><strong>A valid IPv6</strong> address&nbsp;is an IP in the form <code>"x<sub>1</sub>:x<sub>2</sub>:x<sub>3</sub>:x<sub>4:</sub>x<sub>5</sub>:x<sub>6</sub>:x<sub>7</sub>:x<sub>8</sub>"</code> where:</p>

<ul>
	<li><code>1 &lt;= x<sub>i</sub>.length &lt;= 4</code></li>
	<li><code>x<sub>i</sub></code> is a&nbsp;<strong>hexadecimal string</strong> which may contain digits, lower-case English letter (<code>'a'</code> to <code>'f'</code>) and upper-case English letters (<code>'A'</code> to <code>'F'</code>).</li>
	<li>Leading zeros are allowed in <code>x<sub>i</sub></code>.</li>
</ul>

<p>For example,&nbsp;"<code>2001:0db8:85a3:0000:0000:8a2e:0370:7334"</code>&nbsp;and "<code>2001:db8:85a3:0:0:8A2E:0370:7334"</code> are valid IPv6 addresses, while "<code>2001:0db8:85a3::8A2E:037j:7334"</code>&nbsp;and "<code>02001:0db8:85a3:0000:0000:8a2e:0370:7334"</code> are invalid IPv6 addresses.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> IP = "172.16.254.1"
<strong>Output:</strong> "IPv4"
<strong>Explanation:</strong> This is a valid IPv4 address, return "IPv4".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
<strong>Output:</strong> "IPv6"
<strong>Explanation:</strong> This is a valid IPv6 address, return "IPv6".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> IP = "256.256.256.256"
<strong>Output:</strong> "Neither"
<strong>Explanation:</strong> This is neither a IPv4 address nor a IPv6 address.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:"
<strong>Output:</strong> "Neither"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> IP = "1e1.4.5.6"
<strong>Output:</strong> "Neither"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>IP</code> consists only of English letters, digits and the characters <code>'.'</code> and <code>':'</code>.</li>
</ul>
</div>