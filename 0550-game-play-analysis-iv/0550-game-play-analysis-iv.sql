# Write your MySQL query statement below
with first_login as(
    select player_id, min(event_date) as first_date
    from activity
    group by player_id
)
select round(1.0 *count(distinct a.player_id)/count(distinct f.player_id),2) as fraction
from first_login f
left join activity a
on f.player_id = a.player_id
and a.event_date=date_add(f.first_date, interval 1 day);