# Write your MySQL query statement below
SELECT 
p.firstName firstName,
p.lastName lastName,
a.city city,
a.state state
from
Person AS p
LEFT JOIN
Address AS a
ON
p.personId=a.personId;