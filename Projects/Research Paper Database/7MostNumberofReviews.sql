select membername, Largest
from
(select memberid, max(num) as Largest
from (select count(*) as num, memberid
	  from report
      group by memberid) x)y join pcmember pc
      where y.memberid = pc.memberid;