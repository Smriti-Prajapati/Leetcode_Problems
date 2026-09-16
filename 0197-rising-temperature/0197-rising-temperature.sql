# Write your MySQL query statement below
select w1.id
from weather w1 #todays temperature
join weather w2 #yesterdays temperature
on w1.recordDate=date_add(w2.recordDate,interval 1 day)
where w1.temperature> w2.temperature;