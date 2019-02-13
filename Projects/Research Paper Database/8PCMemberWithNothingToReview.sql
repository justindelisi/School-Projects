select memberid, membername
from pcmember
where  memberid NOT IN (
select memberid
from report);
