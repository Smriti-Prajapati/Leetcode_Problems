# Write your MySQL query statement below
with first_order as(
    select customer_id, min(order_date) as first_order_date
    from delivery
    group by customer_id
)
select round(100.0 * sum(d.order_date=d.customer_pref_delivery_date)/count(*),2) as immediate_percentage
from delivery d
join first_order f 
on d.customer_id=f.customer_id and
d.order_date= f.first_order_date;