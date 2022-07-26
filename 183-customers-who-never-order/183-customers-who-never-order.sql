# Write your MySQL query statement below
SELECT customers.name as 'Customers' FROM customers WHERE customers.id NOT IN (SELECT customerid FROM orders);