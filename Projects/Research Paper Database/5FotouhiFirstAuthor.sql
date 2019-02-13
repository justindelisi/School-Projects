use sampledb;

select a.AuthorName, p.title
from author a join authorpaper ap join paper p 
where a.AuthorID = ap.AuthorID && ap.PaperID = p.paperID
&& ap.contribution = 1 && a.AuthorName = 'Fotouhi';