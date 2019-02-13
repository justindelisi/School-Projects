select p.title
from paper p join report r join pcmember pc
where p.paperid = r.paperid && r.memberid = pc.memberid
&& recommendation = 'R' && pc.membername = 'Matt' AND p.title IN 
(select p.title
from paper p join report r join pcmember pc
where p.paperid = r.paperid && r.memberid = pc.memberid
&& recommendation = 'R' && pc.membername = 'John');

