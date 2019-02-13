use sampledb;

select p.title
from author a join authorpaper ap join paper p
where a.AuthorID = ap.AuthorID && p.PaperID = ap.PaperID
&& a.AuthorName = 'Fotouhi' AND p.PaperID IN ( select ap.paperid
from authorpaper ap join author a 
where ap.AuthorID = a.AuthorID
group by ap.PaperID
having count(*)=1);







