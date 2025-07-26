# Write your MySQL query statement below

select * from Cinema where description not like 'b%g' and id%2!=0 order by rating desc;