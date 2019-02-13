use sampledb;

select p.title
from paper p join authorpaper ap join author a
where p.paperid = ap.paperid && a.authorid = ap.authorid
&& a.authorname = 'Fotouhi' AND p.title IN (select p.title
from paper p join authorpaper ap join author a
where p.paperid = ap.paperid && a.authorid = ap.authorid
&& a.authorname = 'Lu');