create view Accepted as
select title as "Accepted Titles"
from paper 
where paperid IN(
select paperid
from report
where recommendation = 'A'
group by paperid
having count(*) >=2);




select *
from Accepted;